#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...);
int handle_string(va_list args, int *count);
int handle_char(va_list args, int *count);
int handle_int(va_list args, int *count);
int handle_bin(va_list args, int count);
int handle_unsigned_int(va_list args, int *count);
int handle_octal(va_list args, int *count);
int handle_hexadecimal(va_list args, int *count, int uppercase);
int handle_non_printable(va_list args, int *count);
int handle_addr(va_list args, int *count);

#endif
