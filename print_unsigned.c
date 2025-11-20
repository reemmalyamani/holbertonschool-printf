#include "main.h"

/**
 * print_unsigned - prints an unsigned long integer
 * @n: number to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_unsigned(unsigned long int n)
{
    int count = 0;
    int res;

    if (n / 10)
    {
        res = print_unsigned(n / 10);
        if (res == -1)
            return (-1);
        count += res;
    }

    if (_putchar((n % 10) + '0') == -1)
        return (-1);

    return (count + 1);
}
