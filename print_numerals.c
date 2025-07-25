#include "main.h"
#include <unistd.h>

/**
 *print_bin - prints binary numbers
 *@num: unsigned number
 *@len: number of character printed
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: the number of character printed
 */

int print_bin(unsigned int num, int len, char *mybuff, int *c)
{
	if (num >= 2)
	{
		len = print_bin(num / 2, len, mybuff, c);
	}
	if (*c >= 1023)
	{
		write(1, mybuff, (*c));
		empty_buff(mybuff, c);
	}
	mybuff[*c] = (num % 2) + '0';
	len++;
	*c += 1;
	return (len);
}


/**
 *print_octal - prints octal numbers
 *@num: unsigned number
 *@len: number of character printed
 *@mybuff: print buffer
 *@c: position on buffer
 *Return: the number of character printed
 */

int print_oct(unsigned int num, int len, char *mybuff, int *c)
{
	if (num >= 8)
	{
		len = print_oct(num / 8, len, mybuff, c);
	}
	if (*c >= 1023)
	{
		write(1, mybuff, (*c));
		empty_buff(mybuff, c);
	}
	mybuff[*c] = (num % 8) + '0';
	*c += 1;
	len++;
	return (len);
}

/**
 *print_hex_big - prints hexadecimal numbers in upper case
 *@num: unsigned number
 *@len: number of character printed
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: the number of character printed
 */

int print_hex_big(unsigned int num, int len, char *mybuff, int *c)
{
	if (num >= 16)
	{
		len = print_hex_big(num / 16, len, mybuff, c);
	}
	if (num % 16 >= 10)
	{
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = ((num % 16) - 10) + 'A';
	}
	else
	{
		if (*c >= 1023)
		{
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = (num % 16) + '0';
	}
	*c += 1;
	len++;
	return (len);
}


/**
 *print_hex - prints hexadecimal numbers in lower case
 *@num: unsigned number
 *@len: number of character printed
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: the number of character printed
 */

int print_hex(unsigned int num, int len, char *mybuff, int *c)
{
	if (num >= 16)
	{
		len = print_hex(num / 16, len, mybuff, c);
	}
	if (num % 16 >= 10)
	{
		if (*c >= 1023)
		{
			write(1, mybuff, (*c));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = ((num % 16) - 10) + 'a';
	}
	else
	{
		if (*c >= 1023)
                {
                        write(1, mybuff, (*c));
                        empty_buff(mybuff, c);
                }
                mybuff[*c] = (num % 16) + '0';
	}
	*c += 1;
	len++;
	return (len);
}


/**
 *print_pointer - prints pointer in lower case
 *@num: unsigned number
 *@len: number of character printed
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: the number of character printed
 */

int print_pointer(unsigned long int num, int len, char *mybuff, int *c)
{
        int i;
        int shift;
        int digit;
	int lead = 1;

        for (i = 15; i >= 0; i--)
        {
                if (*c >= 1023)
                {
                        write(1, mybuff, *c);
                        empty_buff(mybuff, c);
                }
                shift = i * 4;
                digit = (num >> shift) & 0xF;
		if (digit == 0 && lead == 1 && i != 0)
		{
			continue;
		}
		lead = 0;
                if (digit < 10)
		{
                        mybuff[*c] = digit + '0';
                }
		else
		{
                        mybuff[*c] = digit - 10 + 'a';
                }
		(*c)++;
                len++;
        }
        return len;
}
