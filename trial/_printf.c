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
	char *mybuff = _calloc(1024, sizeof(char));

	if (mybuff == NULL)
	{
		return (-1);
	}
	va_start(myargs, format);
	while (format != NULL && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			for (b = 0; b < 10; b++)
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
			special_cases(format, &total, a, status, mybuff, &c);
			a = a + 2;
			total -= 2;
			continue;
		}
		if (c >= 1023 || format[a] == '\n')
		{
			write(1, mybuff,(c));
			empty_buff(mybuff, &c);
		}
		mybuff[c] = format[a];
		c++;
		a++;
	}
	if (c >= 0)
	{
		write(1, mybuff, (c));
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
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
		mybuff[*c] = '%';
		*total += 1;
		*c += 1;
	}
	else if (status != 1)
	{
		if (*c >= 1023)
                {
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
		mybuff[*c] = '%';
		*c += 1;
		a++;
		if (*c >= 1023)
                {
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
		mybuff[*c] = format[a];
		*total += 2;
		*c += 1;
	}
}


/**
 *_calloc - allocate and initializes dynamic memory
 *@num: number of members
 *@Size: size of each member
 *Return: Nothing
 */

void *_calloc(unsigned int num, unsigned int size)
{
	if (num == 0 || size == 0)
	{
		return (NULL);
	}
	else
	{
		void *myptr = malloc(num * size);
		unsigned int a;
		char *new;

		if (myptr == NULL)
		{
			return (NULL);
		}
		new = (char *)myptr;
		for (a = 0; a < (size * num); a++)
		{
			new[a] = 0;
		}
		return (new);
	}
}
