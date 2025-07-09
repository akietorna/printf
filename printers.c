#include <unistd.h>
#include "main.h"

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
 *Return: the length of integer
 */

int print_int(int num,int len)
{
	if (num < 0)
	{
		_putchar('-');
		len++;
		print_int(-num, len);
	}
	if (num >= 10)
	{
		len = print_int(num / 10, len);
	}
	_putchar((num % 10) + '0');
	len++;
	return (len);
}
