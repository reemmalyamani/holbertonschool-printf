#include "main.h"

/**
 * print_number - prints a positive long number
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_number(long n)
{
    int count = 0;

    if (n / 10)
        count += print_number(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}

/**
 * print_int - prints a signed integer
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
    long n = va_arg(ap, int);
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    count += print_number(n);
    return (count);
}
