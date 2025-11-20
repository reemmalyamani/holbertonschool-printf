#include "main.h"

/**
 * get_printer - returns function for a given specifier
 * @c: format specifier
 *
 * Return: pointer to function, or NULL if not found
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
			return (printers[i].f);
		i++;
	}

	return (NULL);
}

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
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i])
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

			if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else
			{
				func = get_printer(format[i]);
				if (func != NULL)
					count += func(ap);
				else
				{
					count += _putchar('%');
					count += _putchar(format[i]);
				}
			}
		}
		i++;
	}

	va_end(ap);
	return (count);
}
