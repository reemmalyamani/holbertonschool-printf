#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct printer - pairs a format specifier with a function
 * @spec: the specifier character
 * @func: pointer to the function that handles it
 */
typedef struct printer
{
    char spec;
    int (*func)(va_list ap);
} printer_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);

#endif /* MAIN_H */
