#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"


/**
 *flags - works on some flags before a specifier
 *@mybuff: printing buffer
 *@format: input string
 *@a: location on format
 *@total: total number of characters printed
 *@c: position on the buffer
 *Return: nothing
 */

void flags(const char *format, int *total, int *a, char *mybuff, int *c)
{
	if ((format[*a + 1] == ' ' || format[*a + 1] == '+') &&
	    (format[*a + 2] == 'd' || format[*a + 2] == 'i'))
	{
		if (*c >= 1023)
		{
			write(1, mybuff, *c);
			empty_buff(mybuff, c);
		}
		mybuff[*c] = format[*a + 1];
		*c += 1;
		*a += 1;
	}
	if (format[*a + 1] == '#' && format[*a + 2] == 'o')
	{
		if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = '0';
                *c += 1;
                *a += 1;
	}
	if (format[*a + 1] == '#' && format[*a + 2] == 'x')
	{
                if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = '0';
                *c += 1;
                *a += 1;
		if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = 'x';
                *c += 1;
                *total += 1;
        }
	if (format[*a + 1] == '#' && format[*a + 2] == 'X')
        {
                if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = '0';
                *c += 1;
                *total += 1;
                if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = 'X';
                *c += 1;
                *a += 1;
        }
}
