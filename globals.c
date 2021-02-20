/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

#include "include.h"

char *port = "/dev/akipic";
char *hexfile = "akipic.hex";
char firm_version[] = "not check connect";/*17 chars*/
unsigned short *pgmbuf;
unsigned short *datbuf;
unsigned short *cfgbuf;
unsigned short *read_cfgbuf;
int ind = 0;
int fd;
unsigned short blank_word;
int pgmtop;
int dattop;
int cfgtop;
int overwrite_cal_dat = 0;
