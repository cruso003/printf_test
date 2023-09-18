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
	size_t len;
	size_t i;

	if (!str)
	{
		str = "(null)";
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		(*count) += i;
	}
	else
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			_putchar(str[i]);
		}
		(*count) += len;
	}
	return (len);
}
