#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


/**
 * print_unsign - print unsigned
 * @ap: The argument pointer.
 * Description: This function prints a unsigned int.
 * Return: 0.
 */
int print_unsign(va_list ap)
{
	unsigned int i;

	unsigned int p = 1;

	unsigned int r;

	unsigned int n = va_arg(ap, int);

	unsigned int len2 = 0;

	i = n;
	r = i;

	while (r > 9)
	{
		p *= 10;
		r /= 10;
	}

	for (; p >= 1; p /= 10)
	{
		len2 += my_putchar(((i / p) % 10) + '0');

	}
	return (len2);
}


/**
 * print_octal - print in octal format
 * @ap: The argument pointer.
 * Description: This function prints a octal number.
 * Return: the length of string
 */

int print_octal(va_list ap)
{
	unsigned int octal = va_arg(ap, int);

	unsigned int buff[1000];

	int  count = 0, i;

	if (octal == 0)
	{
		my_putchar('0');
		return (1);
	}

	while (octal > 0)
	{
		buff[count] = octal % 8;
		octal /= 8;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		my_putchar(buff[i] + '0');
	}
	return (count);
}

/**
 * print_hexlower - convert decimal to hexadecimal in lowercase
 * @ap: The argument pointer
 * Description: This function prints a unsigned hexadecimal
 * Return: the length of output
 */
int print_hexlower(va_list ap)
{
	unsigned int varULL_step = va_arg(ap, int);

	unsigned int varULL_temp = 0;

	char varChr_hexa_temp[1024];

	int i = 0, count = 0;

	if (varULL_step == 0)
	{
		my_putchar('0');

		count = 1;
	}
	else
	while (varULL_step != 0)
	{
		varULL_temp = varULL_step % 16;
		if (varULL_temp < 10)
		{
			varChr_hexa_temp[i] = varULL_temp + 48;
			i++;
		}
		else
		{
			varChr_hexa_temp[i] = varULL_temp + 87;
			i++;
		}
		varULL_step /= 16;
	}
	for (i = i - 1 ; i >= 0; i--)
	{
		count += my_putchar(varChr_hexa_temp[i]);
	}
	return (count);
}


/**
 * print_hexupper - it convert decimal to hexadecimal in uppercase
 * @ap: The argument pointer
 * Description: function displays an unsigned hexadecimal in uppercase.
 * Return: the length of output
 */
int print_hexupper(va_list ap)
{
	unsigned int varULL_step = va_arg(ap, int);

	unsigned int varULL_temp = 0;

	char varChr_hexa_temp[1024];

	int i = 0;

	int count = 0;

	if (varULL_step == 0)
	{
		my_putchar('0');
		count = 1;
	}
	while (varULL_step != 0)
	{
	varULL_temp = varULL_step % 16;
	if (varULL_temp < 10)
	{
	varChr_hexa_temp[i] = varULL_temp + 48;
	i++;
	}
	else
	{
		varChr_hexa_temp[i] = varULL_temp + 55;
		i++;
	}
	varULL_step /= 16;
	}
	for (i = i - 1 ; i >= 0; i--)
	{
		count += my_putchar(varChr_hexa_temp[i]);
	}
	return (count);
}

/**
 * specifier_2 - Process format specifiers and print corresponding values
 *
 * @format: The format string containing the specifier
 * @ap: A va_list of arguments based on the specifier
 *
 * Return: The number of characters printed
 */

int specifier_2(const char *format, va_list ap)
{

	int count = 0;

	if (*format == 'u')
	{
		count += print_unsign(ap);
	}
	else if (*format == 'o')
	{
		count += print_octal(ap);
	}
	else if (*format == 'x')
	{
		count += print_hexlower(ap);
	}
	else if (*format == 'X')
	{
		count += print_hexupper(ap);
	}

	return (count);
}
