#include <unistd.h>
#include "main.h"
#include <limits.h>
#include <stdarg.h>

/**
 *match_big_string - print big string
 *@myargs: arguments
 *@mybuff: print buffer
 *@c: position on buffer
 *Return: lenth of the string
 */

int match_big_string(va_list myargs, char *mybuff, int *c)
{
        char *str = va_arg(myargs, char *);
        int a = 0;
	int total = 0;

	while (str[a] != '\0')
        {
                if (*c >= 1023)
                {
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
		if ((str[a] > 0 && str[a] < 32) || (str[a] >= 127))
		{
			mybuff[*c] = '\\';
			*c += 1;
			total++;
			if (*c >= 1023)
			{
				write(1, mybuff, (*c));
				empty_buff(mybuff, c);
			}
			mybuff[*c] = 'x';
			*c += 1;
			total++;
			if (str[a] < 16)
			{
				if (*c >= 1023)
				{
					write(1, mybuff, (*c));
					empty_buff(mybuff, c);
				}
				mybuff[*c] = '0';
				*c += 1;
				total++;
			}
			total += print_hex_big(str[a], 0, mybuff, c);
			a++;
			total--;
			continue;
		}
		if (*c >= 1023)
                {
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = str[a];
                a++;
                *c += 1;
        }
        return (a + total);
}


/**
 *print_int - prints an integer
 *@num: the integer
 *@len: length of the integer
 *@mybuff: printing buffer
 *@c: position on the buffer
 *Return: the length of integer
 */

int print_int(int num, int len, char *mybuff, int *c)
{
	if (num == INT_MIN)
	{
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = '-';
		*c += 1;
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = '2';
		*c += 1;
		len += 2;
		return (print_int(147483648, len, mybuff, c));
	}
	if (num < 0)
	{
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = '-';
		*c += 1;
		len++;
		return (print_int(-num, len, mybuff, c));
	}
	if (num >= 10)
	{
		len = print_int(num / 10, len, mybuff, c);
	}
	if (*c >= 1023)
	{
		write(1, mybuff, (*c));
		empty_buff(mybuff, c);
	}
	mybuff[*c] = (num % 10) + '0';
	len++;
	*c += 1;
	return (len);
}


/**
 *print_unint - prints an unsigned integer
 *@num: the integer
 *@len: length of the integer
 *@mybuff: print buffer
 *@c: position in the buffer
 *Return: the length of integer
 */

int print_unint(unsigned int num, int len, char *mybuff, int *c)
{
	if (num >= 10)
	{
		len = print_int(num / 10, len, mybuff, c);
	}
	if (*c >= 1023)
	{
		write(1, mybuff, (*c));
		empty_buff(mybuff, c);
	}
	mybuff[*c] = (num % 10) + '0';
	len++;
	*c += 1;
	return (len);
}
