#include "main.h"

/**
 * print_int - prints a signed integer (%d and %i)
 * @ap: argument list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_int(va_list ap)
{
    int n = va_arg(ap, int);
    long ln = n;
    unsigned long num;
    int count = 0;
    int res;

    if (ln < 0)
    {
        if (_putchar('-') == -1)
            return (-1);
        count++;
        ln = -ln;
    }

    num = (unsigned long)ln;

    res = print_unsigned(num);
    if (res == -1)
        return (-1);

    return (count + res);
}
