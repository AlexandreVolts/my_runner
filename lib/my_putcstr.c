/*
** EPITECH PROJECT, 2017
** my_putcstr.c
** File description:
** Put colored text in output
*/

#include "include/lib_prototypes.h"

void my_putnbr(int nbr)
{
	if (nbr < 0) {
		nbr *= -1;
		my_putchar('-');
	}
	if (nbr >= 10)
		my_putnbr(nbr / 10);
	my_putchar(nbr % 10 + '0');
}

void my_putcstr(char *str, int color)
{
	my_putstr("\x1B[");
	my_putnbr(color + 30);
	my_putchar('m');
	my_putstr(str);
	my_putstr("\x1B[0m");
}
