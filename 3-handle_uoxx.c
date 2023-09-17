#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * handle_unsigned_int - Handling specifier for unsigned decimals.
 * @args: Argument list.
 * @count: Pointer to the counter.
 * Return: Count pointer.
 */
int handle_unsigned_int(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int num_digits = snfprint(NULL, 0, "%u", num);
	char buffer[BUFFER_SIZE];
	int len = snprintf(buffer, num_digits + 1, "%u", num);

	write(1, buffer, len);
	*count += len;
	return (*count);
}
/**
 * handle_octal - Handles specifier for octal notation.
 * @args: Argument list.
 * @count: A pointer to count.
 * Return: Pointer to count.
 */
int handle_octal(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char octal_str[BUFFER_SIZE];
	int index = 0;
	int i;

	do {
		octal_str[index++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);
	if (index == 0)
	{
		octal_str[index++] = '0';
	}
	for (i = index - 1; i >= 0; i--;)
	{
		write(1, &octal_str[i], 1);
		(*count)++;
	}
	return (*count);
}
/**
 * handle_hexadecimal - Handles the specifier for printing
 * an integer in hexadecimal (base 16) notation.
 * @args: Argument list.
 * @count: Argument count.
 * @uppercase: Handle cases where the specifier is uppercase.
 * Return: Pointer to count.
 */
int handle_hexadecimal(va_list args, int *count, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int)
		char hex_str[BUFFER_SIZE];

	if (uppercase)
	{
		sprintf(hex_str, "%X", num);
	}
	else
	{
		sprintf(hex_str, "%x", num)
	}
	write(1, hex_str, strlen(hex_str));
	*count += strlen(hex_str);
	return (*count);
}
