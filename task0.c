#include "main.h"

/**
 * print_char - pulls out a character from a variadic function
 * Return: 0;
 */

int print_char(va_list args)
{
	int count;

	char character;

	character = va_arg(args, int);
	if (character)
		return (-1);
	count = write(1, &character, 1);
	return (count);

}
/**
 * print_string - pulls out a string from a variadic list
 * Return:0
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	if (s == NULL)
		return (-1);
	write(1, s, strlen(s));
	return (strlen(s));
}

/**
 * print_cent - print %
 * Return: 0;
 */
int print_cent(va_list args)
{
	return (0);
}
