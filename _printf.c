#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0, count = 0;
    char c;

    if (format == NULL)
        return (-1);

    va_start(ap, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;

            /* lone '%' at end is an error */
            if (format[i] == '\0')
            {
                va_end(ap);
                return (-1);
            }

            c = format[i];

            if (c == 'c')
                count += print_char(ap);
            else if (c == 's')
                count += print_string(ap);
            else if (c == 'd' || c == 'i')
                count += print_int(ap);
            else if (c == '%')
                count += _putchar('%');
            else
            {
                /* unknown specifier: print '%' then the character */
                count += _putchar('%');
                count += _putchar(c);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(ap);
    return (count);
}
