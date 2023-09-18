#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @str: A pointer to type char.
 * Return: len (short for lenght).
 */
size_t _strlen(const char *str)
{
	size_t len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}
