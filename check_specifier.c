#include "main.h"

/**
 * specifier - checks the specifier type inputed
 * @s: the character specifier
 * Return: a pointer to the appropriate function
 */

int (*specifier(const char *format))(va_list)
{
	int j;
	point array[10] = {
		{"c", print_char},
		{"d", printd},
		{"s", print_string},
		{"%", print_cent},
		{"i", printi},
		{NULL, NULL}};

	for (j = 0; array[j].t != NULL; j++)
	{
		if (*(array[j].t) == *format)
			break;
	}					
	return (array[j].f);
}
