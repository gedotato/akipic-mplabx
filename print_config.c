/* Copyright (C) 2000, MIYAMOTO Takanori
 *
 * This is free software, licensed under the GNU Public License V2.
 * See the file LICENSE for details.
 */

#include "include.h"

void print_config_unsupported(void)
{
/* 	printf("akipic has no \"print config status\" code for %s.\n", spec[ind].name); */
/* 	return; */
}

void print_config_16F8X(void)
{
	int config_word;

	print_id();
	config_word = *(cfgbuf + 7) & 0x3fff;
	printf("\nconfig word status...\n");
	printf("\tCP\t%s\n", config_word & 0x10 ? "disable" : "enable");
	printf("\tPWRTE\t%s\n", config_word & 8 ? "disable" : "enable");
	printf("\tWDTE\t%s\n", config_word & 4 ? "enable" : "disable");
	print_oscillator_selection(config_word);
}

void print_config_16F87X4K(void)
{
	int config_word;

	print_id();
	config_word = *(cfgbuf + 7) & 0x3fff;
	printf("\nconfig word status...\n");
	printf("\tBKBUG\t%s\n", config_word & 0x800 ? "disable" : "enable");

	switch(config_word / 0x1000){
	case 0:
		printf("\tCP\t0x0000 to 0x0fff code protected\n");
	case 1:
		printf("\tCP\t0x0800 to 0x0fff code protected\n");
	case 2:
		printf("\tCP\t0x0f00 to 0x0fff code protected\n");
	case 3:
		printf("\tCP\tdisable\n");
	}

	printf("\tWRT\t%s\n", config_word & 0x200 ? "enable" : "disable");
	printf("\tCPD\t%s\n", config_word & 0x100 ? "disable" : "enable");
	printf("\tLVP\t%s\n", config_word & 0x80 ? "enable" : "disable");
	printf("\tBODEN\t%s\n", config_word & 0x40 ? "enable" : "disable");
	printf("\tPWRTE\t%s\n", config_word & 0x8 ? "disable" : "enable");
	printf("\tWDTE\t%s\n", config_word & 0x4 ? "enable" : "disable");
	print_oscillator_selection(config_word);
}

void print_config_16F87X8K(void)
{
	int i, config_word;

	print_id();
	config_word = *(cfgbuf + 7) & 0x3fff;
	printf("\nconfig word status...\n");
	printf("\tBKBUG\t%s\n", config_word & 0x800 ? "disable" : "enable");

	switch(config_word / 0x1000){
	case 0:
		printf("\tCP\t0x0000 to 0x1fff code protected\n");
	case 1:
		printf("\tCP\t0x1000 to 0x1fff code protected\n");
	case 2:
		printf("\tCP\t0x1f00 to 0x1fff code protected\n");
	case 3:
		printf("\tCP\tdisable\n");
	}

	printf("\tWRT\t%s\n", config_word & 0x200 ? "enable" : "disable");
	printf("\tCPD\t%s\n", config_word & 0x100 ? "disable" : "enable");
	printf("\tLVP\t%s\n", config_word & 0x80 ? "enable" : "disable");
	printf("\tBODEN\t%s\n", config_word & 0x40 ? "enable" : "disable");
	printf("\tPWRTE\t%s\n", config_word & 0x8 ? "disable" : "enable");
	printf("\tWDTE\t%s\n", config_word & 0x4 ? "enable" : "disable");
	print_oscillator_selection(config_word);
}

void print_config_16F62X1K(void)
{
	int config_word;

	print_id();
	config_word = cfgbuf[7] & 0x3fff;

	switch(config_word / 0x1000){
	case 0:
		printf("\tCP\t0x0000 to 0x03ff code protected\n");
	case 1:
		printf("\tCP\t0x0200 to 0x03ff code protected\n");
	case 2:
	case 3:
		printf("\tCP\tdisable\n");
	}
	printf("\tCPD\t%s\n", config_word & 0x100 ? "disable" : "enable");
	printf("\tLVP\t%s\n", config_word & 0x80 ? "enable" : "disable");
	printf("\tBODEN\t%s\n", config_word & 0x40 ? "enable" : "disable");
	printf("\tMCLRE\t%s\n", config_word & 0x20 ? "enable" : "disable");
	printf("\tPWRTE\t%s\n", config_word & 0x8 ? "disable" : "enable");
	printf("\tWDTE\t%s\n", config_word & 0x4 ? "enable" : "disable");
	print_oscillator_selection62x(config_word);
}

void print_config_16F62X2K(void)
{
	int config_word;

	print_id();
	config_word = cfgbuf[7] & 0x3fff;

	switch(config_word / 0x1000){
	case 0:
		printf("\tCP\t0x0000 to 0x07ff code protected\n");
	case 1:
		printf("\tCP\t0x0200 to 0x07ff code protected\n");
	case 2:
		printf("\tCP\t0x0400 to 0x07ff code protected\n");
	case 3:
		printf("\tCP\tdisable\n");
	}
	printf("\tCPD\t%s\n", config_word & 0x100 ? "disable" : "enable");
	printf("\tLVP\t%s\n", config_word & 0x80 ? "enable" : "disable");
	printf("\tBODEN\t%s\n", config_word & 0x40 ? "enable" : "disable");
	printf("\tMCLRE\t%s\n", config_word & 0x20 ? "enable" : "disable");
	printf("\tPWRTE\t%s\n", config_word & 0x8 ? "disable" : "enable");
	printf("\tWDTE\t%s\n", config_word & 0x4 ? "enable" : "disable");
	print_oscillator_selection62x(config_word);
}

void print_id(void)
{
	int i;

	printf("\nID information...\n");
	printf("\t");
	for(i = 0; i < 4; i++)
		printf("0x%01x ", cfgbuf[i] & 0xf);
	printf("\n");
}

void print_oscillator_selection(unsigned short config_word)
{
	printf("\tFOSC\t");
	switch(config_word & 3){
	case 0:
		printf("LP\n");
		break;
	case 1:
		printf("XT\n");
		break;
	case 2:
		printf("HS\n");
		break;
	case 3:
		printf("RC\n");
		break;
	default:
		break;
	}
}

void print_oscillator_selection62x(unsigned short config_word)
{
	unsigned short fosc;

	printf("\tFOSC\t");
	fosc = (config_word & 3) | ((config_word & 0x10)?4:0);
	switch(fosc){
	case 0:
		printf("LP\n");
		break;
	case 1:
		printf("XT\n");
		break;
	case 2:
		printf("HS\n");
		break;
	case 3:
		printf("EC\n");
		break;
	case 4:
		printf("INTRCGPIO\n");
		break;
	case 5:
		printf("INTRCCLK\n");
		break;
	case 6:
		printf("ERGPIO\n");
		break;
	case 7:
		printf("ERCLK\n");
		break;
	default:
		break;
	}
}

