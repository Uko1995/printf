#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<string.h>
#include<unistd.h>

int _printf(const char *format, ...);
//int _printf_int(const char *format, ...);


/*functions.c*/
//char _printchar(char c, va_list args);
//char *_printstring(char *s, va_list args);
//int _printd(int d, va_list args);
//int _printi(int i, va_list args);
typedef struct function
{
	char *t;
	int(*f)(va_list args);
}point;
int print_char(va_list args);
int print_string(va_list args);
int print_cent(va_list args);
int printi(va_list args);
int printd(va_list args);
int (*specifier(const char *format))(va_list);



#endif
