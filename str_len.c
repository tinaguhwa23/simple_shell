#include "head.h"

/**
 * _strlen - This will compute the length of a string.
 *
 * @str1: Its a type char pointer
 *
 * Return: length of string.
 */
int _strlen(const char *str1)
{
	int len;

	for (len = 0; str1[len] != 0; len++)
		;
	return (len);
}
