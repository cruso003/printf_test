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
int handle_char(va_list args, int *count)
{
	char _char = (char)va_arg(args, int);

	_putchar(_char);
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
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		len = strlen(str);
		write(1, str, len);
		*count += len;
	}
	return (len);
}
