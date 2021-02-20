/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

#include "include.h"

struct picdevice spec[] = {
	{"",       0,    0,   0,   0,    0,          print_config_unsupported},
	{"12c508", 512,  0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12c508a",512,  0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12c509", 1024, 0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12c509a",1024, 0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12ce518",512,  0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12ce519",1024, 0,   5,   12,   TYPE_12C5X, print_config_unsupported},
	{"12c671", 1024, 0,   8,   14,   TYPE_12C67X, print_config_unsupported},
	{"12c672", 2048, 0,   8,   14,   TYPE_12C67X, print_config_unsupported},
	{"12ce673",1024, 0,   8,   14,   TYPE_12C67X, print_config_unsupported},
	{"12ce674",2048, 0,   8,   14,   TYPE_12C67X, print_config_unsupported},
	{"16c55",  512,  0,   5,   12,   TYPE_16C5XO, print_config_unsupported},
	{"16c55a", 512,  0,   5,   12,   TYPE_16C5XO, print_config_unsupported},
	{"16c57",  2048, 0,   5,   12,   TYPE_16C5XO, print_config_unsupported},
	{"16c57c", 2048, 0,   5,   12,   TYPE_16C5XO, print_config_unsupported},
	{"16c54",  512,  0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c54a", 512,  0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c54c", 512,  0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c56",  1024, 0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c56a", 1024, 0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c58a", 2048, 0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c58b", 2048, 0,   5,   12,   TYPE_16C5XE, print_config_unsupported},
	{"16c554", 512,  0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c556", 1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c558", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c61",  1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c620", 512,  0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c620a",512,  0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c621", 1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c621a",1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c622", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c622a",2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c623", 512,  0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c624", 1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c625", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c62",  2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c62a", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c62b", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c63",  4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c63a", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c64",  2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c64a", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c65",  4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c65a", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c65b", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c66",  8192, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c67",  8192, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c710", 512,  0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c711", 1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c712", 1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c717", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c71",  1024, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c72",  2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c72a", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c73",  4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c73a", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c73b", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c74",  4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c74a", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c74b", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c76",  8192, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c770", 2048, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c771", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c773", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c774", 4096, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c77",  8192, 0,   8,   14,   TYPE_16CX, print_config_unsupported},
	{"16c84",  1024, 64,  8,   14,   TYPE_16FX, print_config_16F8X},
	{"16f627", 1024, 128, 8,   14,   TYPE_16FX, print_config_16F62X1K},
	{"16f628", 2048, 128, 8,   14,   TYPE_16FX, print_config_16F62X2K},
	{"16f83",  512,  64,  8,   14,   TYPE_16FX, print_config_16F8X},
	{"16f84",  1024, 64,  8,   14,   TYPE_16FX, print_config_16F8X},
	{"16f84a", 1024, 64,  8,   14,   TYPE_16FX, print_config_16F8X},
	{"16f873", 4096, 128, 8,   14,   TYPE_16FX, print_config_16F87X4K},
	{"16f874", 4096, 128, 8,   14,   TYPE_16FX, print_config_16F87X4K},
	{"16f876", 8192, 256, 8,   14,   TYPE_16FX, print_config_16F87X8K},
	{"16f877", 8192, 256, 8,   14,   TYPE_16FX, print_config_16F87X8K},
	{"",       0,    0,   0,   0,    0        , print_config_unsupported}};

void read_program_memory(void)
{
	unsigned short tmp;

	switch(spec[ind].access_type){
	case TYPE_16C5XE:
		write(fd, "rps", 3);
		akipic_to_buffer(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		break;
	case TYPE_16C5XO:
		write(fd, "rpl", 3);
		akipic_to_buffer(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		break;
	case TYPE_12C5X:
		write(fd, "rsp", 3);
		akipic_to_buffer(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		tmp = pgmbuf[0];
		memmove(pgmbuf, &pgmbuf[1], (spec[ind].pgmsize + spec[ind].cfgsize - 1) * sizeof(tmp));
		pgmbuf[spec[ind].pgmsize + spec[ind].cfgsize - 1] = tmp;
		break;
	case TYPE_16CX:
		write(fd, "rsp", 3);
		akipic_to_buffer(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		break;
	case  TYPE_12C67X: case TYPE_16FX:
		write(fd, "rsp", 3);
		akipic_to_buffer(pgmbuf, spec[ind].pgmsize);
		break;
	defalut:
		break;
	}
}

void read_data_memory(void)
{
	switch(spec[ind].access_type){
	case TYPE_16C5XE: 
	case TYPE_16C5XO:
	case TYPE_12C5X:
	case TYPE_12C67X:
	case TYPE_16CX:
		break;
	case TYPE_16FX:
		write(fd, "rsd", 3);
		akipic_to_buffer(datbuf, spec[ind].datsize);
		break;
	defalut:
		break;
	}
}

void read_config_word(void)
{
	switch(spec[ind].access_type){
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_16CX:
	case TYPE_12C5X:
		break;
	case  TYPE_12C67X: case TYPE_16FX:
		write(fd, "rsc", 3);
		akipic_to_buffer(cfgbuf, spec[ind].cfgsize);
		break;
	defalut:
		break;
	}
}

void write_program_memory(int pgmend)
{
	unsigned short tmp;

	switch(spec[ind].access_type){
	case TYPE_16C5XE:
		write(fd, "wps", 3);
		buffer_to_akipic(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		break;
	case TYPE_16C5XO:
		write(fd, "wpl", 3);
		buffer_to_akipic(pgmbuf, spec[ind].pgmsize + spec[ind].cfgsize);
		break;
	case TYPE_12C5X:
		tmp = pgmbuf[spec[ind].pgmsize + spec[ind].cfgsize - 1];
		memmove(&pgmbuf[1], pgmbuf, (spec[ind].pgmsize + spec[ind].cfgsize - 1) * sizeof(tmp));
		pgmbuf[0] = tmp;
		write(fd, "wsp", 3);
		buffer_to_akipic(pgmbuf, overwrite_cal_dat ? spec[ind].pgmsize + spec[ind].cfgsize : pgmend + 1);
		break;
	case  TYPE_12C67X:  case TYPE_16CX:
		write(fd, "wsp", 3);
		buffer_to_akipic(pgmbuf, pgmend);
		break;
	case TYPE_16FX:
		write(fd, "wef", 3);
		buffer_to_akipic(pgmbuf, pgmend);
		break;
	defalut:
		break;
	}
}

void write_data_memory(int datend)
{
	switch(spec[ind].access_type){
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_12C5X:
	case TYPE_12C67X:
	case TYPE_16CX:
		break;
	case TYPE_16FX:
		write(fd, "wed", 3);
		buffer_to_akipic(datbuf, datend);
		break;
	defalut:
		break;
	}
}
void write_config_word(int cfgend)
{
	switch(spec[ind].access_type){
	case TYPE_16C5XE:
	case TYPE_16C5XO:
	case TYPE_12C5X:
		break;
	case  TYPE_12C67X:
		fill_reservedarea12C67X();
		write(fd, "wsc", 3);
		buffer_to_akipic(cfgbuf, cfgend);
		break;
	case TYPE_16CX:
		fill_reservedarea00();
		write(fd, "wsc", 3);
		buffer_to_akipic(cfgbuf, cfgend);
		break;
	case TYPE_16FX:
		/* fill_reservedarea00(); */
		write(fd, "wec", 3);
		buffer_to_akipic(cfgbuf, cfgend);
		break;
	defalut:
		break;
	}
}

int akipic_to_buffer(unsigned short *buf, int size)
{
	int i;
	unsigned short *add;
	char c ,s[2];

	s[0] = size / 0x100;
	s[1] = size % 0x100;
	write(fd, s, 2);
	for (i = 0; i < size ; i++){
		add = &buf[i];
		read(fd, &s[0], 1);/*use `read(fd, s, 2)` get wrong data*/
		read(fd, &s[1], 1);
		*add = ((unsigned short)s[0] & 0xff) * 0x100 + ((unsigned short)s[1] & 0xff);
		print_address(add, size);
	}
	return(check_endmark());
}

int buffer_to_akipic(unsigned short *buf, int size)
{
	int i;
	unsigned short *add;
	char c, s[2];

	s[0] = size / 0x100;
	s[1] = size % 0x100;
	write(fd, s, 2);
	for(i = 0; i < size; i++){
		add = &buf[i];
		read(fd,&c,1);/* read 8bit counter */
		s[0] = *add / 0x100;
		s[1] = *add % 0x100;
		write(fd, s, 2);
		print_address(add, size);
	}
	return(check_endmark());
}

void print_address(unsigned short *add, int size)
{
	unsigned short *baseadd;
	char c;

	if(add < cfgbuf){
		printf("Program memory");
		baseadd = pgmbuf;
		if(add - baseadd == spec[ind].pgmsize - 1 || add - baseadd == size -1)
			c = '\n';
		else
			c = '\r';
	}
	else if(add < datbuf){
		printf("Config word");
		baseadd = cfgbuf;
		size = size > spec[ind].cfgsize ? size - spec[ind].pgmsize : size;
		c = (add - baseadd == size - 1) ? '\n' : '\r';
	}
	else{
		printf("Data memory");
		baseadd = datbuf;
		c = (add - baseadd == size - 1) ? '\n' : '\r';
	}
	printf(" = %04X%c", (unsigned short)(add - baseadd), c);
}

void print_config_status(void)
{
	printf("Oops! undocumented option.\n");
	printf("future release will available(maybe).\n");
	/* spec[ind].print_config_status(); */
}



int check_endmark(void)
{
	char c;
	read(fd, &c, 1);
	if(c != '@'){
		printf("Illegal End Mark catched.\n");
		printf("Check your serial cable & AKI-PIC\n\n");
		return(0);
	}
	else
		return(1);
}

void fill_reservedarea00()
{
	int i;

	for(i = 4; i <= 6; i++)/* Filling reserved-area = 0x00 prevents wrong cfg-words*/
		*(cfgbuf + i) = 0;
}

void fill_reservedarea12C67X()
{
	int i;

	write(fd, "rsc", 3);
	akipic_to_buffer(read_cfgbuf, spec[ind].cfgsize);

	for(i = 0; i <= 1; i++)
		*(cfgbuf + i) |= 0x3FF0;
	for(i = 4; i <= 6; i++)/* Replace reserved-area with rsc data*/
		*(cfgbuf + i) = *(read_cfgbuf + i);
}

int bd(void)
{
	int c;

	write(fd, "bd", 2);
	return(check_endmark());
}

/*
 * Unused functions
 *
 *
 */
int bs(void)
{
	char s[2];

	write(fd, "bs", 2);
	s[0] = spec[ind].pgmsize / 0x100;
	s[1] = spec[ind].pgmsize % 0x100;
	write(fd, s, 2);
	read(fd, &s[0], 1);/*use `read(fd, s, 2)` get wrong data*/
	read(fd, &s[1], 1);
	if((s[0] & 0xff) * 0x100 + (s[1] & 0xff) == blank_word)
		return(1);
	else
		return(0);
}

int bpl(void)
{
/* ???blank check??????? */
	return(0);
}

int bps(void)
{
/* ???blank check??????? */
	return(0);
}





/*
 * Akiduki's windows software not use these commands
 * but implepented in firm-ware
 *
 */

int wee(void)
{
/* ????write memory?????? */
	return(0);
}


void mta(int a)/* Do "TRIS PORTA" */
{
	write(fd, "mta", 3);
	write(fd, &a, 1);
}

void mtb(int b)/* Do "TRIS PORTB" */
{
	write(fd, "mtb", 3);
	write(fd, &b, 1);
}

void mtc(int a)/* Do "TRIS PORTC" */
{
	int c;

	write(fd, "mtc", 3);
	write(fd, &c, 1);
}

int mr(void)/* Read FSR */
{
	int c;

	write(fd, "mr`", 2);
	read(fd, &c, 1);
	return(c);
}

int mra(void)/* Read PORTA */
{
	int c;

	write(fd, "mra", 3);
	read(fd, &c, 1);
	return(c);
}

int mrb(void)/* Read PORTB */
{
	int c;

	write(fd, "mrb", 3);
	read(fd, &c, 1);
	return(c);
}

int mrc(void)/* Read PORTC */
{
	int c;

	write(fd, "mr`", 3);
	read(fd, &c, 1);
	return(c);
}

void mw(int c)/* Write FSR */
{
	write(fd, "mw`", 3);
	write(fd, &c, 1);
}

void mwa(int c)/* Write PORTA */
{
	write(fd, "mwa", 3);
	write(fd, &c, 1);
}

void mwb(int c)/* Write PORTB */
{
	write(fd, "mwb", 3);
	write(fd, &c, 1);
}

void mwc(int c)/* Write PORTC */
{
	write(fd, "mwc", 3);
	write(fd, &c, 1);
}
