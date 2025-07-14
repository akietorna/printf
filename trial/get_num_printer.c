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
	return (print_bin(va_arg(myargs, int), 0));
}
