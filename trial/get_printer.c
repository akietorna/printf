#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>


/**
 *match_string - prints a string
 *@myargs: the string
 *Return: number of characther
 */

int match_string(va_list myargs)
{
	char *str = va_arg(myargs, char *);

	str = (str == NULL) ? "(null)" : str;
	write(1, str, _strlen(str));
	return (_strlen(str));
}

/**
 *match_char - prints a charather
 *@myargs: the character
 *Return: number of characther
 */

int match_char(va_list myargs)
{
	_putchar(va_arg(myargs, int));
	return (1);
}

/**
 *match_int - prints an integer
 *@myargs: the integer
 *Return: number of characther
 */

int match_int(va_list myargs)
{
	return (print_int(va_arg(myargs, int), 0));
}
