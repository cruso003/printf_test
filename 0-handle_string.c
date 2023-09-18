#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * handle_char - Helper function to write a character to stdout.
 * @args: The argument list.
 * Return: 1.
 */
int handle_char(va_list args)
{
	char _char = (char)va_arg(args, int);

	_putchar(_char);
	return (1);
}
/**
 * handle_string - Helper function to write a string to stdout.
 * @args: The argument list.
 * @count: Argument count.
 * Return: len.
 */
int handle_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);
	int len;

	if (!str)
	{
		str = "(null)";
	}
	for (len = 0; str[len]; len++)
	{
		_putchar(str[len]);
		if (count != NULL)
		{
			(*count)++;
		}
	}
	return (len);
}
/**
 * handle_percent - Handles percent specifier by printing the ascii value
 * Return: 1.
*/
int handle_percent(void)
{
		_putchar(37);
		return (1);
}

