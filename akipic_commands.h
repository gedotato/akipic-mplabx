/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

void read_program_memory(void);
void read_data_memory(void);
void read_config_word(void);
void write_program_memory(int pgmend);
void write_data_memory(int datend);
void write_config_word(int cfgend);
int akipic_to_buffer(unsigned short *buf, int size);
int buffer_to_akipic(unsigned short *buf, int size);
void print_address(unsigned short *add, int size);
void print_config_status(void);
int check_endmark(void);
void fill_reservedarea00(void);
void fill_reservedarea12C67X(void);
int bs(void);
int bd(void);
int wee(void);
int bpl(void);
int bps(void);
void mta(int a);
void mtb(int b);
void mtc(int c);
int mr(void);
int mra(void);
int mrb(void);
int mrc(void);
void mw(int c);
void mwa(int c);
void mwb(int c);
void mwc(int c);

struct picdevice {
	char *name;
	unsigned int pgmsize;
	unsigned int datsize;
	unsigned int cfgsize;
	int arch;
	int access_type;
	void (*print_config_status)(void);
/* 	int pgmtop; */
/* 	int dattop; */
/* 	int cfgtop; */
	};
extern struct picdevice spec[];
