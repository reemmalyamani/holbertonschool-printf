#include "main.h"

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
    char *s;
    int count = 0;

    s = va_arg(ap, char *);
    if (s == NULL)
        s = "(null)";

    while (*s)
    {
        if (_putchar(*s) == -1)
            return (-1);
        s++;
        count++;
    }

    return (count);
}
