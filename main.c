#include <stdio.h>
#include "main.h"

int main(void)
{
    char c = 'A';
    char *str = "Hello, World!";
    int num = 42;

    printf("Testing custom _printf function:\n");

    _printf("Character: %c\n", c);
    printf("Character: %c\n", c);

    _printf("String: %s\n", str);
    printf("String: %s\n", str);

    _printf("Percent sign: %%\n");
    printf("Percent sign: %%\n");

    _printf("Integer: %d\n", num);
    printf("Integer: %d\n", num);

    _printf("Unsupported: %r\n");
    printf("Unsupported: %r\n");

    return (0);
}
