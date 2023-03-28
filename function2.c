#include "main.h"

/**
 * print_R - A function that prints a string in rot13 format
 * @R: string to print
 * Return: number of printed characters
 */

int print_R(va_list R)
{
	char *str;
	unsigned int i = 0, j = 0;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				_putchar(out[j]);
				counter++;
				break;
			}
		}
		if (!in[j])
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_S - A function that prints a string and nonprintable
 * character ascii values
 * @S: string to print
 * Return: number of printed characters
 */
int print_S(va_list S)
{
	unsigned int i = 0;
	int counter = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			counter += 2;
			counter += print_x(S);
		}
		else
		{
			_putchar(str[i]);
			counter++;
		}
	}
	return (counter);
}


/**
 * print_X - A function that prints an ascii character value
 * in uppercase hexadecimal
 * @X: char to print
 * Return: number of printed characters
 */
int print_X(va_list X)
{
	unsigned int a[8];
	unsigned int j = 1, m = 268435456, n, sum = 0;
	char diff;
	int counter;

	n = va_arg(X, unsigned int);
	diff = 'A' - ':';
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

/**
 * print_b - A function that prints an unsigned int i binary notation
 * @b: unsigned in to print
 * Return: number of printed digits
 */
int print_b(va_list b)
{
	unsigned int n, m = 2147483648, j = 1, sum = 0;
	unsigned int a[32];
	int counter = 0;/*a counter variable*/

	n = va_arg(b, unsigned int);
	a[0] = n / m;

	for (; j < 32; j++)
	{
		m /= 2;
		a[j] = (n / m) % 2;
	}
	for (j = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}

/**
 * print_o - A function that prints an unsigned int in octal notation
 * @o: unsigned int to print
 * Return: number of printed digits
 */
int print_o(va_list o)
{
	unsigned int a[11];
	unsigned int j = 1, m = 1073741824, n, sum = 0;
	int counter;

	n = va_arg(o, unsigned int);
	a[0] = n / m;
	for (; j < 11; j++)
	{
		m /= 8;
		a[j] = (n / m) % 8;
	}
	for (j = 0; j < 11; j++)
	{
		sum += a[j];
		if (sum || j == 10)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}
