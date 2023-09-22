#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * print_character - print character
 * @ap: argument pointer
 * Return: 1
 */

int print_character(va_list ap)
{
	int ch = (char)va_arg(ap, int);

	my_putchar(ch);

	return (1);
}

/**
 * print_string - print string
 * @ap: argument pointer
 * Return: 1
 */

int print_string(va_list ap)
{
	int i = 0;
	char *s;

	s = va_arg(ap, char*);

	if (s == NULL)
	{
		s = "(null)";
	}

	while (s[i] != '\0')
	{
		my_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_decint - Print a decimal integer.
 *
 * @arg: A va_list containing the integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_decint(va_list arg)
{
	unsigned int i, j, k;

	int n = va_arg(arg, int), len2 = 0;

	if (n < 0)
	{
		len2 += my_putchar('-');
		i = n * -1;
	}
	else
	{
		i = n;
	}
	j = 1;
	k = i;
	while (k > 9)
	{
		j *= 10;
		k /= 10;
	}
	for (; j >= 1; j /= 10)
	{
		len2 += my_putchar(((i / j) % 10) + '0');
	}
	return (len2);
}

/**
 * print_binary - convert decimal to binary. Base 10 to Base 2
 * @ap: argument pointer
 * Description: reverse the modulo on recursive division
 * Return: length of the binary number
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, int), binary[1024];

	int i = 0, j = 0;

	if (n == 0)
	{
		my_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		my_putchar(binary[j] + '0');
	}
	return (i);
}

/***************************SPECIFIER FUNCTION.****************************/

/**
 * specifier1 - Format and print data according to a format specifier.
 *
 * @format: A format string containing format specifiers.
 * @ap: A va_list containing the arguments to be formatted and printed.
 *
 * Return: The total number of characters printed.
 */

int specifier1(const char *format, va_list ap)
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

			if (*format == 'c')
			{
				count += print_character(ap);
			}
			else if (*format == 's')
			{
				count += print_string(ap);
			}
			else if (*format == '%')
			{
				count += my_putchar('%');

			}
			else if (*format == 'd' || *format == 'i')
			{
				count += print_decint(ap);
			}
			else if (*format == 'b')
			{
				count += print_binary(ap);
			}
			else if (*format == 'u' || *format == 'o' *format == 'x'||
					*format == 'X')
			{
				count += specifier_handler1(format, ap);
			}
		}
		format++;
	}
	return (count);
}
