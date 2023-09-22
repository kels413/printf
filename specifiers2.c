#include "main.h"

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

