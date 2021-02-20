/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

#include "include.h"

void read_INHX8M(int *pgmend, int *datend, int *cfgend)
{
	int raw, add, baseadd, data,c, i, j, k;
	char tmp2[] = "00";
	char tmp4[] = "0000";
	FILE *hexfd;
	*pgmend = pgmtop;
	*datend = dattop;
	*cfgend = cfgtop;

	if((hexfd = fopen(hexfile, "r"))== NULL){
		printf("Can't open --- %s\n", hexfile);
		exit(0);
	}
	clear_buffer();
	while((c = fgetc(hexfd)) != EOF){
		if(c == ':'){
			fread(tmp2, 1, 2, hexfd);
			raw = strtol(tmp2, (char **)NULL, 16);
			fread(tmp4, 1, 4, hexfd);
			baseadd = strtol(tmp4, (char **)NULL, 16);
			fread(tmp2, 1, 2, hexfd);
			if(strtol(tmp2, (char **)NULL, 16) == 1)
				break; /* check end mark */
			for(i = 0; i < raw; i += 2){
				fread(tmp4, 1, 4, hexfd);
				data = strtol(tmp4, (char **)NULL, 16);
				data = (data % 0x100) * 0x100 + (data / 0x100);
				add = baseadd + i;
				INHX8M_to_buffer(add, data, pgmend, datend, cfgend);
			}
			fread(tmp2, 1, 2, hexfd); /* get checksum */ 
		}
	}
	*pgmend = (*pgmend - pgmtop) / 2 + 1;	/* convert word */
	*datend = (*datend - dattop) / 2 + 1;
	*cfgend = (*cfgend - cfgtop) / 2 + 1;
	fclose(hexfd);
}

void INHX8M_to_buffer(int add, int data, int *pgmend, int *datend, int *cfgend)
{
	if(pgmtop <= add && add < pgmtop + spec[ind].pgmsize * 2){
		pgmbuf[(add - pgmtop)/2] = (unsigned short)(data & blank_word);
		*pgmend = *pgmend > add ? *pgmend : add;
	}
	else if(cfgtop <= add && add < cfgtop + spec[ind].cfgsize * 2){
		cfgbuf[(add - cfgtop)/2] = (unsigned short)(data & blank_word);
		*cfgend = *cfgend > add ? *cfgend : add;
	}
	else if(dattop <= add && add < dattop + spec[ind].datsize * 2){
		data = (blank_word & 0xff00) + (data & 0xff);/* keep H on 7bit higher may avoid error(reported by Mitsuiwa-san.THANX!) */
		datbuf[(add - dattop)/2] = (unsigned short)data;
		*datend = *datend > add ? *datend : add;
	}
	else{
		printf("Out of PIC memory!! ------%04x\n ", add);
		exit(0);
	}
}

void write_INHX8M(void)
{
	FILE *hexfd;
	int add, sum, i, j, k;

	if((hexfd = fopen(hexfile, "w+"))== NULL){
		printf("Can't open --- %s\n", hexfile);
		exit(0);
	}
	buffer_to_INHX8M(hexfd, pgmbuf, spec[ind].pgmsize, pgmtop);
	buffer_to_INHX8M(hexfd, datbuf, spec[ind].datsize, dattop);
	buffer_to_INHX8M(hexfd, cfgbuf, spec[ind].cfgsize, cfgtop);
	fprintf(hexfd, ":00000001FF");
	fclose(hexfd);
}

void buffer_to_INHX8M(FILE *hexfd, unsigned short *buf, unsigned int size, unsigned int offset)
{
	int sum, add, i, j, k;

	for (add = 0, sum = 0; add < size * 2; add++){
		if (add % COLUMN == 0){
			i = (size * 2 - add) >= COLUMN ? COLUMN : size * 2 - add;
			j = (add + offset) / 0x100;
			k = (add + offset) % 0x100;
			sum += i + j + k;
			fprintf(hexfd, ":%02X%02X%02X00", i, j, k);
		}
		j = add % 2 ? buf[add / 2] / 0x100 : buf[add / 2] % 0x100;
		fprintf(hexfd, "%02X", j);
		sum += j;
		if ((add % COLUMN == COLUMN - 1)||(size * 2 == add + 1)){
			fprintf(hexfd, "%02X\n", (0 - sum) & 0xff);
			sum = 0;
		}
	}
}
