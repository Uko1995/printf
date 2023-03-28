#include "main.h"
/**
 * _print - prints to std output
 * @format: the format string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int (*f)(va_list);
	int value;
	int i, count;
	va_list args;
	va_start(args, format);

	count = 0;

	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] !='%')
		{
			value = write(1, &format[i], 1);
			count += value;
			i++;
			continue;
		}
		if (format[i] == '%')
		{	
			if (f != NULL)
			{
				f = specifier(&format[i + 1]);
			}
			else
			{
				if (f == NULL)
					return (-1);
			
				count += f(args);
				i += 2;
				continue;
			}	
		}
		i++;
	}
	va_end(args);
	return (count);
}
