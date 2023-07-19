#include "function_pointers.h"
#include <stdlib.h>

int _putchar(char c)
{
    /* Implementation of _putchar goes here */
    return write(1, &c, 1);
}

void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
    {
        f(name);
    }
}

void print_char(char *c)
{
    _putchar(*c);
}

void print_name_char_by_char(char *name)
{
    while (*name)
    {
        _putchar(*name);
        name++;
    }
}
