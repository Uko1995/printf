#include "main.h"

/**
 * printd - pulls decimals from variadic list
 * Return: number of integers
 */
int printd(va_list args)
{
	int count = 0;
	int d = va_arg(args, int);
	count = write(1, &d, sizeof(int));
	
	return (count);
}

/**
 * printi - pulls integers from variadic list
 * Return: number of integers printed
 */

int printi(va_list args)
{
	int count  = 0;

	int i = va_arg(args, int);
	count = write(1, &i, sizeof(int));
	return (count);
}
