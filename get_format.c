#include "main.h"
void (*format)(const char *format)
{
        while (*format != '\0')
        {
                switch (*format)
                {
                        case 'c':
                                return (_printchar);
                                break;
                        case 's':
                                return (_printstring);
                                break;
                        case 'd':
                                return (_printd);
                                break;
                        case 'i':
                                return (_printi);
		}
	}
}	
