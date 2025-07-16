#include <unistd.h>
#include "main.h"
#include <limits.h>

/**
 *_putchar - prints a character
 *@c: the character
 *return: Nothing
 */

void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 *_strlen - tells the length of a string
 *@str: the string
 *Return: length of string
 */

int _strlen(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
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
		mybuff[*c + 1] = '2';
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
