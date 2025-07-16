#include <stdarg.h>
#include "main.h"
#include <limits.h>

/**
 *match_bin - gets to print binary numbers
 *@myargs: the number
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of characther
 */

int match_bin(va_list myargs, char *mybuff, int *c)
{
	return (print_bin(va_arg(myargs, unsigned int), 0, mybuff, c));
}

/**
 *match_oct - gets to print octal numbers
 *@myargs: the number
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of characther
 */

int match_oct(va_list myargs, char *mybuff, int *c)
{
	return (print_oct(va_arg(myargs, unsigned int), 0, mybuff, c));
}


/**
 *match_unint - gets to print unsigned integers
 *@myargs: the number
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of characther
 */

int match_unint(va_list myargs, char *mybuff, int *c)
{
	return (print_unint(va_arg(myargs, unsigned int), 0, mybuff, c));
}


/**
 *match_hex_big - gets to print hexadecimal numbers
 *@myargs: the number
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of characther
 */

int match_hex_big(va_list myargs, char *mybuff, int *c)
{
	return (print_hex_big(va_arg(myargs, unsigned int), 0, mybuff, c));
}


/**
 *match_hex - gets to print hexadecimal numbers
 *@myargs: the number
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of characther
 */

int match_hex(va_list myargs, char *mybuff, int *c)
{
	return (print_hex(va_arg(myargs, unsigned int), 0, mybuff, c));
}
