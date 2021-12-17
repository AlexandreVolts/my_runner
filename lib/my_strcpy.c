/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** Copy a str into another
*/

void my_strcpy(char *dest, char const *src)
{
	int i = 0;
	for (; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}
