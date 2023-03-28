#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, or -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - A function that prints a char
 * @c: character to print
 * Return: Always 1 (Success)
 */
int print_c(va_list c)
{
	char character = (char)va_arg(c, int);

	_putchar(character);
	return (1);
}

/**
 * print_s - A function that prints a string
 * @s: string to print
 * Return: i
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}
/**
 * print_d - pulls integers from a variadic function
 * @i: function parameter
 * Return: counter
 */
int print_d(va_list i)
{
	int a[10];
	int j = 1, m = 1000000000, n, sum = 0, counter = 0;

	n = va_arg(i, int);
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
		counter++;
	}
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_i - A function that prints a base 10 integer
 * @i: integer to print
 * Return: number of printed digits
 */
int print_i(va_list i)
{
	int a[10];
	int j = 1, m = 1000000000, n, sum = 0, counter = 0;

	n = va_arg(i, int);
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
		counter++;
	}
	a[0] = n / m;

	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}

	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}
