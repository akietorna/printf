#include "main.h"

/**
 *print_bin - prints binary numbers
 *@num: unsigned number
 *@len: number of character printed
 *Return: the number of character printed
 */

int print_bin(unsigned int num, int len)
{
	if (num > 2)
	{
		len = print_bin(num / 2, len);
	}
	_putchar((num % 2) + '0');
	len++;
	return (len);
}
