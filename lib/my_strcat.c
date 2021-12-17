/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** Concatenate two strings 
*/

char *my_strcat(char *dest, char const *src)
{
	int len;
	int i;

	for (len = 0; dest[len] != '\0'; len++);
	for (i = 0; src[i] != '\0'; i++) {
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';

	return (dest);
}
