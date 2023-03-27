#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
    unsigned int count = 0;
    va_list args;
    int len;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, sizeof(char));
                count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s == NULL) s = "(null)";
                len = strlen(s);

                write(1, s, len);
                count += len;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int d = va_arg(args, int);
                char buf[32];

                int len = snprintf(buf, sizeof(buf), "%d", d);

                write(1, buf, len);
                count += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, format, 1);
                count++;
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

    return count;
}

