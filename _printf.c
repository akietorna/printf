#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 *_printf - print a string
 *@format: the string with format specifiers
 *Return: total number of character printed
 */

int _printf(const char *format, ...)
{
	def_func printer[] = {
		{'c', match_char},
		{'s', match_string},
		{'i', match_int},
		{'d', match_int}
	};
	va_list myargs;
	int a = (format == NULL) ? 1 : 0;
	int total = 0;
	int b;

	va_start(myargs, format);
	while (format != NULL && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			for (b = 0; b < 4; b++)
			{
				if (format[a + 1] == printer[b].arg)
				{
					total += printer[b].print(myargs);
					break;
				}
			}
			if (format[a + 1] == '\0')
			{
				return (1);
			}
			if (format[a + 1] == '%')
			{
				_putchar('%');
				total += 1;
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


/**
 *special_cases - work on special cases
 *@format: characther string
 *@total: pointer to total number of characters
 *@a: position in the format array
 *Return: Nothing
 */

void special_cases(const char *format, int *total, int a)
{
	if (format[a + 1] == '%')
	{
		_putchar('%');
		*total += 1;
	}
	else
	{
		_putchar('%');
		_putchar(format[a + 1]);
		*total += 2;
	}
}
