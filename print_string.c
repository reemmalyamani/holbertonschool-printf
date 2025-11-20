#include "main.h"

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: number of characters printed or -1 on error
 */
int print_string(va_list ap)
{
    char *s = va_arg(ap, char *);
    int count = 0;

    if (s == NULL)
        s = "(null)";

    while (s[count] != '\0')
    {
        if (_putchar(s[count]) == -1)
            return (-1);
        count++;
    }

    return (count);
}
