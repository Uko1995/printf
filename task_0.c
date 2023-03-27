#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: input string
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int d, i;
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
					write(1, &c, sizeof(char));
					count ++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					write(1, s, strlen(s));
					count += strlen(s);
					break;
				case 'd':
					d = va_arg(args, int);
					write(1, &d, sizeof(d));
					count++;
					break;
				case 'i':
					i = va_arg(args, int);
					write(1, &i, sizeof(i));
					count++;
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, format, 1);
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
