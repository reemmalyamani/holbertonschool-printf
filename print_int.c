#include "main.h"

/**
 * print_int - prints a signed integer
 * @args: va_list containing the integer
 *
 * Return: number of characters printed, or -1 on error
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    unsigned int num;
    int count = 0, printed;

    if (n < 0)
    {
        if (_putchar('-') == -1)
            return (-1);
        num = (unsigned int)(-n);
        count++;
    }
    else
    {
        num = (unsigned int)n;
    }

    printed = print_unsigned(num);
    if (printed == -1)
        return (-1);

    return (count + printed);
}
