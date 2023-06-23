#include "main.h"
/**
 * print_number - Function that prints an integer.
 * @n: int type number
 * Description: Can only use _putchar to print.
 */
void print_number(int n) {
    if (n == 0) {
        _putchar('0');
        return;
    }

    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    int divisor = 1;
    while (n / divisor >= 10) {
        divisor *= 10;
    }

    while (divisor != 0) {
        int digit = n / divisor;
        _putchar('0' + digit);
        n %= divisor;
        divisor /= 10;
    }
}

