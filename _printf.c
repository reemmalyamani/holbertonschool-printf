#include "main.h"

/**
 * get_printer - selects the correct function for a specifier
 * @c: the format specifier
 *
 * Return: pointer to the function, or NULL if not found
 */
static int (*get_printer(char c))(va_list)
{
    printer_t printers[] = {
        {'c', print_char},
        {'s', print_string},
        {'d', print_int},
        {'i', print_int},
        {'\0', NULL}
    };
    int i = 0;

    while (printers[i].spec != '\0')
    {
        if (printers[i].spec == c)
            return (printers[i].func);
        i++;
    }

    return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: a format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int i, count = 0;
    int (*func)(va_list);
    int printed;

    if (format == NULL)
        return (-1);

    va_start(ap, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            if (_putchar(format[i]) == -1)
            {
                va_end(ap);
                return (-1);
            }
            count++;
            continue;
        }

        i++;
        if (format[i] == '\0')
        {
            va_end(ap);
            return (-1);
        }

        if (format[i] == '%')
        {
            if (_putchar('%') == -1)
            {
                va_end(ap);
                return (-1);
            }
            count++;
            continue;
        }

        func = get_printer(format[i]);
        if (func != NULL)
        {
            printed = func(ap);
            if (printed == -1)
            {
                va_end(ap);
                return (-1);
            }
            count += printed;
        }
        else
        {
            if (_putchar('%') == -1 || _putchar(format[i]) == -1)
            {
                va_end(ap);
                return (-1);
            }
            count += 2;
        }
    }

    va_end(ap);
    return (count);
}
