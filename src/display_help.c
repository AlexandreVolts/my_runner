/*
** EPITECH PROJECT, 2018
** display_help.c
** File description:
** Display help and usage of the program
*/

#include "lib_prototypes.h"

void display_help(void)
{
	my_putcstr("Finite runner created with CSFML.\n\n", 3);
	my_putcstr("USAGE\n", 1);
	my_putcstr("\tmy_runner map.txt\n\n", 1);
	my_putcstr("OPTIONS\n", 5);
	my_putcstr("\t-h\t\tPrint the usage and quit.\n\n", 5);
	my_putcstr("USER INTERACTIONS\n", 4);
	my_putcstr("\tMenu interactions:\n", 4);
	my_putcstr("\t\tUP_KEY & DOWN_KEY\t Choose an option.\n", 4);
	my_putcstr("\t\tRETURN_KEY & SPACE_KEY\t", 4);
	my_putcstr("Validate a choosen option.\n", 4);
	my_putcstr("\tGame interactions:\n", 4);
	my_putcstr("\t\tSPACE_KEY & UP_KEY\tJump.\n", 4);
}
