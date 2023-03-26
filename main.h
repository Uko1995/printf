#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<string.h>
#include<unistd.h>

int _printf(const char *format, ...);
int _printf_int(const char *format, ...);


/*functions.c*/
char _printchar(char c, va_list args);
char _printchar(char *s, va_list args);
int _printchar(int d, va_list args);
int _printchar(char i, va_list args);


#endif
