#include "main.h"

/**
 * _printchar - handles character format specifier
 * @c: character variable
 * @args: parameter
 *
 * Return: c
 */

char _printchar(char c, va_list args)
{
	c = va_arg(args, int);
	write(1, &c, sizeof(char));
	return (c);
}

/**
 * _printstring - handles string format specifier
 * @s: string variable
 * @args: parameter
 *
 * Return: s
 */

char *_printstring(char *s, va_list args)
{	
	s = va_arg(args, char *);
	write(1, s, strlen(s));
	return (s);
}

/**
 * _printd - handles d format specifier
 * @d: integer variable
 * @args: parameter
 *
 * Return: d
 */

int _printd(int d, va_list args)
{	
	d = va_arg(args, int);
	write(1, &d, sizeof(int));
	return (d);
}

/**
 * _printi - handles i format specifier
 * @i: integer variable
 * @args: parameter
 *
 * Return: i
 */

int _printi(int i, va_list args)
{	
	i = va_arg(args, int);
	write(1, &i, sizeof(int));
	return (i);
}
