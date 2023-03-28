#include "main.h"

/**
 * print_p - A function that prints an address
 * @p: address to print
 * Return: number of printed characters
 */
int print_p(va_list p)
{
	int counter = 0;
	unsigned int a[16];
	unsigned int i = 0, sum = 0;
	unsigned long n, m = 1152921504606846976;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (; str[i]; i++)
		{
			_putchar(str[i]);
			counter++;
		}
		return (counter);
	}
	_putchar('0');
	_putchar('x');
	counter = 2;

	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_r - A function that prints a string in reverse
 * @r: string to print
 * Return: number of printed characters
 */
int print_r(va_list r)
{
	char *str;
	int i = 0, counter = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	while (str[i])
		i++;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		counter++;
	}
	return (counter);
}

/**
 * print_u - A function that prints an unsigned integer
 * @u: unsigned int to print
 * Return: number of printed digits
 */
int print_u(va_list u)
{
	unsigned int a[10];
	unsigned int j = 1, m = 1000000000, n, sum = 0;
	int counter = 0;

	n = va_arg(u, unsigned int);
	a[0] = n / m;
	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum || j == 9)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_x - A function that prints an ascii char value in
 * lowercase hexadecimal
 * @x: char to print
 * Return: number of printed characters
 */
int print_x(va_list x)
{
	unsigned int a[8];
	unsigned int j = 1, m = 268435456, n, sum = 0;
	char diff;
	int counter = 0;

	n = va_arg(x, unsigned int);
	diff = 'a' - ':';
	a[0] = n / m;
	for (; j < 8; j++)
	{
		m /= 16;
		a[j] = (n / m) % 16;
	}
	for (j = 0; j < 8; j++)
	{
		sum += a[j];
		if (sum || j == 7)
		{
			if (a[j] < 10)
				_putchar('0' + a[j]);
			else
				_putchar('0' + diff + a[j]);
			counter++;
		}
	}
	return (counter);
}
