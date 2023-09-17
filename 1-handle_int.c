#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * handle_int - handling integers specifiers d and i
 * @args: argument list
 * @count: integer pointer count.
 * Return: len
 */
int handle_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	char int_str[BUFFER_SIZE];
	int len = snprintf(int_str, sizeof(int_str), "%d", num);

	write(1, int_str, len);
	*count += len;
	return (len);
}
