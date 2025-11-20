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

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(ap);
				return (-1);
			}

			if (format[i] == 'c')
				count += print_char(ap);
			else if (format[i] == 's')
				count += print_string(ap);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(ap);
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		i++;
	}

	va_end(ap);
	return (count);
}
