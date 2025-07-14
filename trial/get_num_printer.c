#include <stdarg.h>
#include "main.h"
#include <limits.h>

/**
 *match_bin - gets to print binary numbers
 *@myargs: the number
 *Return: length of characther
 */

int match_bin(va_list myargs)
{
	return (print_bin(va_arg(myargs, unsigned int), 0));
}

/**
 *match_oct - gets to print octal numbers
 *@myargs: the number
 *Return: length of characther
 */

int match_oct(va_list myargs)
{
	return (print_oct(va_arg(myargs, unsigned int), 0));
}


/**
 *match_unint - gets to print unsigned integers
 *@myargs: the number
 *Return: length of characther
 */

int match_unint(va_list myargs)
{
	return (print_unint(va_arg(myargs, unsigned int), 0));
}


/**
 *match_hex_big - gets to print hexadecimal numbers
 *@myargs: the number
 *Return: length of characther
 */

int match_hex_big(va_list myargs)
{
	return (print_hex_big(va_arg(myargs, unsigned int), 0));
}


/**
 *match_hex - gets to print hexadecimal numbers
 *@myargs: the number
 *Return: length of characther
 */

int match_hex(va_list myargs)
{
	return (print_hex(va_arg(myargs, unsigned int), 0));
}
