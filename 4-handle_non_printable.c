#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * handle_non_printable - handles d specifier 4 non-profitable chars using %S
 * @args: arguement list
 * @count: arguement count
 * Return: arguement count pointer
 */
int handle_non_printable(va_list args, int *count)
{
	char *input = va_arg(args, char*);
	char *output = (char *)malloc(strlen(input) * 4 + 1);
	int i, j = 0;
	char current_char;

	if (output == NULL)
	{
		return (-1);
	}
	for (i = 0; input[i] != '\0'; i++)
	{
		current_char = input[i];
		if (current_char < 32 || current_char >= 127)
		{

			snprintf(output + j, 5, "\\x%02X", (unsigned char)current_char);
			j += 4;
		}
		else
		{
			output[j] = current_char;
			j++;
		}
	}
	output[j] = '\0';
	write(1, output, strlen(output));
	free(output);
	*count += j;
	return (*count);
}
