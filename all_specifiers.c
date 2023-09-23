#include "main.h"

/***************************SPECIFIER FUNCTION.****************************/

/**
 * all_specifier - Format and print data according to a format specifier.
 *
 * @format: A format string containing format specifiers.
 * @ap: A va_list containing the arguments to be formatted and printed.
 *
 * Return: The total number of characters printed.
 */

int all_specifier(const char *format, va_list ap)
{
	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			my_putchar(*format);
			count++;
		}
		else
		{
			format++;

			if (*format == 'c' || *format == 's' || *format == '%'
					|| *format == 'd' || *format == 'i' || *format == 'b')
			{
				count += specifiers_1(format, ap);
			}
			else if(*format == 'u' || *format == 'o' || *format == 'x'
					|| *format == 'X')
			{
				count += specifier_2(format, ap);
			}
		}
		format++;
	}

	return (count);

}

