#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...);

/**
 * print_char - prints a character
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list ap);

/**
 * print_string - prints a string
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap);

/**
 * print_int - prints an integer
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list ap);

#endif /* MAIN_H */
