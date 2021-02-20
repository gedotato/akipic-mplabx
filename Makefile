# Copyright (C) 2000, MIYAMOTO Takanori
#
# This is free software, licensed under the GNU Public License V2.
# See the file LICENSE for details.

CC = gcc
OBJS = globals.o akipic_commands.o hexfile.o akipic.o print_config.o
CFLAGS = -g -I.
PROGRAM = akipic

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all : $(PROGRAM)

$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)

$(OBJS) : include.h defines.h globals.h akipic_commands.h hexfile.h akipic.h print_config.h

clean :
	rm -f *~
	rm -f *.o
	rm -f $(PROGRAM)

install :
	cp $(PROGRAM) /usr/local/bin

uninstall :
	rm -f /usr/local/bin/$(PROGRAM)
