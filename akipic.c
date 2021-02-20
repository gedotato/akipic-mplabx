/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

#include "include.h"

int main(int argc, char *argv[])
{
	int i;
	char c;
	int cmd = 0;
	char *tmp;
	char *dev="16f84";

	if (argc < 2) {
		print_help();
		exit(0);
	}

	tmp=getenv("AKIPICPORT");
	if (tmp != NULL)
		port = tmp;

	while((c = getopt(argc, argv, "w:r:d:p:sbeohvc")) != -1){
		switch(c){
		case 'w': case 'r':
			cmd = c;
			hexfile = optarg;
			break;
		case 's':
			cmd = c;
			break;
		case 'b': case 'e':
			cmd = c;
			break;
		case 'd':
			dev = optarg;
			break;
		case 'p':
			port = optarg;
			break;
		case 'h': case 'v': case 'c':
			cmd = c;
			break;
		case 'o':
			overwrite_cal_dat = 1;
			break;
		default:
			break;
		}
	}

	for (ind = 0, i =1; strlen(spec[i].name); i++)
		if (!strcmp(dev, spec[i].name))
			ind = i;
	if (!ind){
		printf("Unknown device --- %s\n", dev);
		exit(0);
	}

	if(!cmd){
		print_help();
		exit(0);
	}

	switch(cmd){
	case 'h':
		i = print_help();
		exit(1);
		break;
	case 'v':
		i = print_version();
		exit(1);
		break;
	case 'c':
		print_catalog();
		exit(1);
		break;
	}

	fd = open(port, O_RDWR | O_NOCTTY );
	if (fd <0){
		perror(port);
		exit(-1);
	}

	if(!check_connection()){
		printf("Connection error !!\n");
		exit(0);
	}

	pgmbuf = (unsigned short *)malloc((spec[ind].pgmsize+spec[ind].cfgsize) * sizeof(unsigned short));
	datbuf = (unsigned short *)malloc(spec[ind].datsize * sizeof(unsigned short));
	if(spec[ind].cfgsize > 0){
		cfgbuf = &pgmbuf[spec[ind].pgmsize];
		read_cfgbuf = (unsigned short *)malloc(spec[ind].cfgsize * sizeof(unsigned short));
	}else{
		cfgbuf = NULL;
		read_cfgbuf = NULL;
	}

	blank_word =(1 << spec[ind].arch) - 1 ;
	clear_buffer();

	set_address_in_hexfile();

	switch (cmd){
	case 'w':
		i = write_pic();
		break;
	case 'r':
		i = read_pic();
		break;
	case 's':
		spec[ind].print_config_status();
		i = 1;
		break;
	case 'b':
		i = blankcheck();
		break;
	case 'e':
		i = erase_pic();
		break;
	default:
		unknown_option_error();
		break;
	}

	close(fd);

//	if(pgmbuf != NULL)
//		free(pgmbuf);
//	if(datbuf != NULL)
//		free(datbuf);
//	if(read_cfgbuf != NULL)
//		free(read_cfgbuf);
	return(i);
}

int read_pic(void)
{
	set_serialport(0, 1);
	read_program_memory();
	read_data_memory();
	read_config_word();
	spec[ind].print_config_status();
	write_INHX8M();
	return(1);
}

int write_pic(void){
	int pgmend;
	int datend;
	int cfgend;
	int i;

	read_INHX8M(&pgmend, &datend, &cfgend);
	spec[ind].print_config_status();
	set_serialport(0, 1);
	write_program_memory(pgmend);
	write_data_memory(datend);
	write_config_word(cfgend);
	return(1);
}

int erase_pic(void)
{
	set_serialport(0, 1);
	if(!spec[ind].datsize){
		printf("%s has no EEPROM.\n", spec[ind].name);
		exit(0);
	}
	bd();/* erase program memory */
//	write_data_memory(datend);
	printf("Erase OK\n\n");
	return(1);
}

int blankcheck(void){
	int i, j, k, l;
	char c;

	set_serialport(0, 1);
	read_program_memory();
	for ( i = 0, j = 1; i < spec[ind].pgmsize; i++)
		if (pgmbuf[i] != blank_word)
			j = 0;
	printf("program memory blank check %s.\n", j ? "OK" : "NG");
	if(spec[ind].datsize){
		read_data_memory();
		for ( i = 0, k = 1; i < spec[ind].datsize; i++)
			if (datbuf[i] != blank_word)
				k = 0;
		printf("data memory blank check %s.\n", k ? "OK" : "NG");
	}
	read_config_word();
	for ( i = 0, l = 1; i < spec[ind].cfgsize; i++)
		if (cfgbuf[i] != blank_word)
			l = 0;
	printf("config word blank check %s.\n", l ? "OK" : "NG");

	return(j | k | l);
}

int unknown_option_error(void)
{
	printf("Unknown Option!!\n");
	printf("\"akipic -h\" for more detail option.\n");
	return(0);
}

void clear_buffer(void)
{
	int i;

	for(i = 0; i < spec[ind].pgmsize; i++){
		pgmbuf[i] = blank_word;
	}
	for(i = 0; i < spec[ind].datsize; i++){
		datbuf[i] =  blank_word;
	}
	for(i = 0; i < spec[ind].cfgsize; i++){
		cfgbuf[i] =  blank_word;
	}
}

int check_connection(void)
{
	int i, j;

	set_serialport(1, 0);
	write(fd, "***?", 4);
	for(i = 0; i < 17; i++)
		read(fd, &firm_version[i], 1);
	firm_version[15] = 0;
	if(strncmp(firm_version, "AKIPIC-PGMV", 11) == 0 && firm_version[16] == '@')
		return(1);
	else
		return(0);
}


int print_version(void)
{
	printf("AKIPIC writer 0.1.8alpha-mplabx-version\n");
	fd = open(port, O_RDWR | O_NOCTTY );
	if (fd <0){
		printf("firmware version...unknown\n");
		printf("\tcan't open %s\n", port);
		return(0);
	}
	if(check_connection()){
		printf("firmware version...%s\n", firm_version);
	}
	else{
		printf("firmware version...unknown\n");
		printf("\tnot connected or power-off.\n");
	}
	return(1);
}

int print_help(void)
{
	int i;

	print_version();
	printf("\nUsage:");
	printf("\t[-p serial-device] [-d taget-device] -r|-w hex-file\n");
	printf("\tor\n");
	printf("\t[-p serial-device] [-d taget-device] -b|-e\n");
	printf("\t\tif variable AKIPICPORT set,use instead of option -p device.\n");
	printf("\n");
	printf("Options:\n");
	printf("\t-w write PIC\n");
	printf("\t-r read PIC\n");
	printf("\t-e erase all memory\n");
	printf("\t-b blank check\n");
	printf("\t-o overwrite internal OSC calibration data\n");
	printf("\t\t(only 12c5*/12ce* available)\n");
	printf("\n\tex)\n\takipic -p /dev/ttyS0 -d 16f84 -w myfile.hex\n\n");
	printf("supported devices are\n");
	for(i = 1; strlen(spec[i].name); i ++){
		printf("\t%s", spec[i].name);
		if(i % 8 == 0)
			printf("\n");
	}
	printf("\n");
	return(1);
}

int set_serialport(int vtime, int vmin)
{
	struct termios setting;

	bzero(&setting, sizeof(setting));
	setting.c_cflag = CS8 | CLOCAL | CREAD;
	setting.c_iflag = IGNBRK | IGNPAR;
	setting.c_oflag = 0;
	setting.c_lflag = 0;
	setting.c_cc[VTIME] = vtime;
	setting.c_cc[VMIN] = vmin;

	tcflush(fd, TCIOFLUSH);
	cfsetispeed(&setting, B9600);
	cfsetospeed(&setting, B9600);
	tcsetattr(fd,TCSANOW,&setting);
}

void set_address_in_hexfile(void)
{
	switch (spec[ind].access_type){
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_12C5X:
	case TYPE_12C67X:
	case TYPE_16CX:
	case TYPE_16FX:
	default:
		pgmtop = 0;
		break;
	}

	switch (spec[ind].access_type){
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_12C5X:
	case TYPE_12C67X:
	case TYPE_16CX:
	case TYPE_16FX:
	default:
		dattop = 0x4200;
		break;
	}

	switch (spec[ind].access_type){
	case TYPE_12C5X:
		cfgtop = 0x2000 - spec[ind].cfgsize * 2;
		break;
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_12C67X:
	case TYPE_16CX:
	case TYPE_16FX:
	default:
		cfgtop = 0x4000;
		break;
	}
}

void print_catalog(void)
/* OMAKE code */
{
	int i;

	printf("name\tN-bit\tpgm-mem\tdat-mem\n");
	for(i = 1; strlen(spec[i].name); i ++){
		printf("%s\t%d\t%d\t%d\n", spec[i].name, spec[i].arch, spec[i].pgmsize, spec[i].datsize);
	}
}
