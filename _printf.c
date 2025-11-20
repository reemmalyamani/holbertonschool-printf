#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string with format
 *
 * Return: number of characters printed,
 *         or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0, count = 0, printed;

    if (format == NULL)
        return (-1);

    va_start(ap, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            if (_putchar(format[i]) == -1)
            {
                va_end(ap);
                return (-1);
            }
            count++;
        }
        else
        {
            i++;

            if (format[i] == '\0')
            {
                va_end(ap);
                return (-1);
            }

            if (format[i] == 'd' || format[i] == 'i')
            {
                printed = print_int(ap);
                if (printed == -1)
                {
                    va_end(ap);
                    return (-1);
                }
                count += printed;
            }
            else if (format[i] == '%')
            {
                if (_putchar('%') == -1)
                {
                    va_end(ap);
                    return (-1);
                }
                count++;
            }
            else
            {
                /* unknown specifier: print '%' then the char */
                if (_putchar('%') == -1 || _putchar(format[i]) == -1)
                {
                    va_end(ap);
                    return (-1);
                }
                count += 2;
            }
        }
        i++;
    }

    va_end(ap);
    return (count);
}
