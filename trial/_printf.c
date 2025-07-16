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
	va_list myargs;
	int a = (format == NULL) ? -1 : 0;
	int total = 0;
	int b;
	int c = 0;
	int status = 0;
	char *mybuff = malloc(1024 * sizeof(char));

	if (mybuff == NULL)
	{
		return (-1);
	}
	va_start(myargs, format);
	while (format != NULL && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			for (b = 0; b < 9; b++)
			{
				if (format[a + 1] == printer[b].arg)
				{
					total += printer[b].print(myargs, mybuff,
								  &c);
					status = 1;
					break;
				}
			}
			if (format[a + 1] == '\0')
			{
				va_end(myargs);
				free(mybuff);
				return (-1);
			}
			if (c >= 1022 || format[a] == '\n')
			{
				write(1, mybuff,(c + 1));
				empty_buff(mybuff, &c);
			}
			special_cases(format, &total, a, status, mybuff, &c);
			a = a + 2;
			total -= 2;
			continue;
		}
		if (c >= 1022 || format[a] == '\n')
		{
			write(1, mybuff,(c + 1));
			empty_buff(mybuff, &c);
		}
		mybuff[c] = format[a];
		c++;
		a++;
	}
	if (c >= 0)
	{
		write(1, mybuff, (c + 1));
	}
	va_end(myargs);
	free(mybuff);
	return (total + a);
}


/**
 *special_cases - work on special cases
 *@format: characther string
 *@total: pointer to total number of characters
 *@a: position in the format array
 *@status: checks if special case is needed
 *@mybuff: printing buffer
 *@c: position in the buffer
 *Return: Nothing
 */

void special_cases(const char *format, int *total, int a,
		   int status, char *mybuff, int *c)
{
	if (format[a + 1] == '%')
	{
		mybuff[*c] = '%';
		*total += 1;
		*c += 1;
	}
	else if (status != 1)
	{
		mybuff[*c] = '%';
		mybuff[*c + 1] = format[a + 1];
		*total += 2;
		*c += 2;
	}
}
