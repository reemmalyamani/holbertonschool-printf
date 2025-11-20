#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_int(va_list args);
int print_unsigned(unsigned int n);

#endif /* MAIN_H */
