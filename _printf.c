#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_format_specifier - Handles a specific format specifier character.
 * @format_char: The format specifier character(e.g., 'c', 's', 'd', etc.).
 * @args: Argument list for the format specifier( va_list).
 * @count: A pointer to the count of characters written.
 * Return: The updated count.
 */
int handle_format_specifier(const char format_char, va_list args, int *count)
{
	switch (format_char)
	{
		case 'c':
			return (handle_char(args, count));
		case 's':
			return (handle_string(args, count));
		default:
			write(1, "%r", 3);
			*count += 3;
			return (*count);
	}
}
/**
 * _printf - Custom printf that produces output according to a format.
 * @format: A character string containing format specifiers.
 * Return: Total count of characters written.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i;
	int count = 0;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else
			{
				count += handle_format_specifier(format[i], args, &count);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
