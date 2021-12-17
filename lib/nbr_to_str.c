/*
** EPITECH PROJECT, 2017
** nbr_to_str.c
** File description:
** Convert a number to a string
*/

#include <stdlib.h>

int int_len(int nbr)
{
	int i = 0;

	if (nbr < 0) {
		nbr *= -1;
		i++;
	}
	if (nbr == 0)
		return (1);
	for (; nbr != 0; i++) {
		nbr /= 10;
	}

	return (i);
}

char *nbr_to_str(int nbr)
{
	char *output = malloc(sizeof(char) * (int_len(nbr) + 1));
	int i = int_len(nbr) - 1;

	output[int_len(nbr)] = '\0';
	if (nbr < 0) {
		output[i] = '-';
		i--;
	}
	for (; i >= 0; i--) {
		output[i] = (nbr % 10) + '0';
		nbr /= 10;
	}

	return (output);
}
