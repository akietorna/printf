#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 *printer - determines the right function to use
 *
 */

def_func printer[] =
{
	{'c', match_char},
	{'s', match_string},
	{'i', match_int},
	{'d', match_int}
};



/**
 *_printf - print a string
 *@fornat: the string with format specifiers
 *Return: total number of character printed
 */

int _printf(const char *format, ...)
{
	va_list myargs;
	int a = 0;
	int total = 0;

	va_start(myargs, format);
	while (format != NULL && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			int b;

			for (b = 0; b < 4; b++)
			{
				if (format[a + 1] == printer[b].arg)
				{
					total += printer[b].print(myargs);
					break;
				}
			}
			if (format[a + 1] == '%')
			{
				_putchar('%');
			}
			a = a + 2;
			total -= 2;
			continue;
		}
		_putchar(format[a]);
		a++;
	}
	return (total + a);
}
