#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * _printf - prints to std output
 * @format: the format string
 * Return: returns th number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int count = 0;
	char c, *s;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, sizeof(c));
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					write(1, s, strlen(s));
					/*count++;*/
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:

					write(1, format, strlen(format));
					break;
			}

		}

		format++;
	}
	va_end(args);
	return (0);
}
