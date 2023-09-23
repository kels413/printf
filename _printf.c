#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - custom to depict the original printf.
 * @format: the string to print and format by specifiers.
 * Description: built by Kelvin and Afia.
 * Return: lenght of the output on sucess.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);

	if ((!format) || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	count = all_specifier(format, ap);

	va_end(ap);
	return (count);
}
