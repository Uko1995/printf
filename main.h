#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<string.h>
#include<unistd.h>

int _printf(const char *format, ...);
int _printf_int(const char *format, ...);


/*functions.c*/
char _printchar(char c, va_list args);
char _printstring(char *s, va_list args);
int _printd(int d, va_list args);
int _printi(int i, va_list args);
void (*format)(const char *format);


#endif
