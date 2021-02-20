/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

void read_INHX8M(int *pgmend, int *datend, int *cfgend);
void INHX8M_to_buffer(int add, int data, int *pgmend, int *datend, int *cfgend);
void write_INHX8M(void);
void buffer_to_INHX8M(FILE *hexfd, unsigned short *buf, unsigned int size, unsigned int offset);
