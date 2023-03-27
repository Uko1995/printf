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
	int d = 0;
	int i = 0;
	char c = '\0';
	char *s = '\0';
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{	
			format++;
			if (*format == 'c')
			{	_printchar(c, args);
				count++;
			}
			else if (*format == 's')
			{	_printstring(s, args);
				count++;
				 /*while (*s)
				 {	
					 write(1, s, strlen(s));
                    			s++;
                    			count++;
				 }*/	
			}
			else if (*format == 'd')
			{	_printd(d, args);
				count++;
			}
			else if	 (*format == 'i')
			{	_printi(i, args);
				count++;
			}	
			else if (*format == '%')
				write(1, "%", 1);
			else
				write (1, format, strlen(format));
		}
		format++;
	}
	va_end(args);
	return (count);
}
