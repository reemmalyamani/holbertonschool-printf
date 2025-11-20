#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list ap)
{
    char c;

    c = (char)va_arg(ap, int);
    _putchar(c);
    return (1);
}
