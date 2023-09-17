#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * handle_char - Helper function to write a character to stdout.
 * @args: The argument list
 * @count: A pointer to the count of characters written.
 * Return: 1.
 */
int handle_char(va_list args, *count)
{
	char _char = (char)va_arg(args, int);

	write(1, &_char, 1);
	(*count)++;
	return (1);
}
/**
 * handle_string - Helper function to write a string to stdout.
 * @args: The argument list.
 * @count: A pointer to the count of written characters.
 * Return: len.
 */
int handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int len;

	if (!str)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	{
		len = strlen(str);
		write(1, str, len);
		*count += len;
	}
	return (len);
}
