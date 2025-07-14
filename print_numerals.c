#include "main.h"

/**
 *print_bin - prints binary numbers
 *@num: unsigned number
 *@len: number of character printed
 *Return: the number of character printed
 */

int print_bin(unsigned int num, int len)
{
	if (num >= 2)
	{
		len = print_bin(num / 2, len);
	}
	_putchar((num % 2) +'0');
	len++;
	return (len);
}


/**
 *print_octal - prints octal numbers
 *@num: unsigned number
 *@len: number of character printed
 *Return: the number of character printed
 */

int print_oct(unsigned int num, int len)
{
	if (num >= 8)
	{
		len = print_oct(num / 8, len);
	}
	_putchar((num % 8) +'0');
	len++;
	return (len);
}

/**
 *print_hex_big - prints hexadecimal numbers in upper case
 *@num: unsigned number
 *@len: number of character printed
 *Return: the number of character printed
 */

int print_hex_big(unsigned int num, int len)
{
	if (num >= 16)
	{
		len = print_hex_big(num / 16, len);
	}
	if (num % 16 >= 10)
	{
		_putchar(((num % 16) - 10) + 'A');
	}
	else
	{
		_putchar((num % 16) + '0');
	}
	len++;
	return (len);
}


/**
 *print_hex - prints hexadecimal numbers in lower case
 *@num: unsigned number
 *@len: number of character printed
 *Return: the number of character printed
 */

int print_hex(unsigned int num, int len)
{
	if (num >= 16)
	{
		len = print_hex(num / 16, len);
	}
	if (num % 16 >= 10)
	{
		_putchar(((num % 16) - 10) + 'a');
	}
	else
	{
		_putchar((num % 16) + '0');
	}
	len++;
	return (len);
}
