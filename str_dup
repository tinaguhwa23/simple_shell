#include "head.h"

/**
 * _strdup - This will duplicate a str in the heap memory.
 *
 * @str1: Its a type char pointer str
 *
 * Return: duplicated str
 */
char *_strdup(const char *str1)
{
	char *new;
	size_t len;

	len = _strlen(str1);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, str1, len + 1);
	return (new);
}
