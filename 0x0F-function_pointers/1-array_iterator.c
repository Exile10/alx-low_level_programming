#include "function_pointers.h"
#include <stdlib.h>

int _putchar(char c)
{
    /* Implementation of _putchar goes here */
    return write(1, &c, 1);
}

void array_iterator(int *array, size_t size, void (*action)(int))
{
    if (array != NULL && action != NULL)
    {
        for (size_t i = 0; i < size; i++)
        {
            action(array[i]);
        }
    }
}

void print_int(int num)
{
    /* Example action function: Print an integer */
    char buffer[20];
    int i = 0;
    int is_negative = 0;

    if (num == 0)
    {
        _putchar('0');
        return;
    }

    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (is_negative)
    {
        _putchar('-');
    }

    while (i > 0)
    {
        _putchar(buffer[--i]);
    }
}

