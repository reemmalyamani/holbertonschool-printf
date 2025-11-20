#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct printer - specifier and print function
 * @spec: format specifier
 * @f: function that prints that type
 */
typedef struct printer
{
	char spec;
	int (*f)(va_list ap);
} printer_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);

#endif /* MAIN_H */
