#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

/**
 * handle_addr - handle specifier for printing memory address
 * @args: arguement list
 * @count: arguement count
 * Return: count
 */
int handle_addr(va_list args, int *count)
{
	uintptr_t addr = va_arg(args, uintptr_t);

	char addr_str[BUFFER_SIZE];

	snprintf(addr_str, sizeof(addr_str), "%#lx", (unsigned long)addr);
	write(1, addr_str, strlen(addr_str));
	count += strlen(addr_str);
	return (*count);
}
