/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** Get the length of a str
*/

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);

	return (i);
}
