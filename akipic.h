/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

int read_pic(void);
int write_pic(void);
int erase_pic(void);
int blankcheck(void);
int unknown_option_error(void);
void clear_buffer(void);
int check_connection(void);
int print_version(void);
int print_help(void);
int set_serialport(int vtime, int vmin);
void set_address_in_hexfile(void);
void print_catalog(void);
