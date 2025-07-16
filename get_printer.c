#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>


/**
 *match_string - prints a string
 *@myargs: the string
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: number of characther
 */

int match_string(va_list myargs, char *mybuff, int *c)
{
	char *str = va_arg(myargs, char *);
	int a = 0;

	str = (str == NULL) ? "(null)" : str;
	while (str[a] != '\0')
	{
		if (*c >= 1022 || mybuff[*c] == '\n')
		{
			write(1, mybuff, (*c + 1));
			empty_buff(mybuff, c);
		}
		mybuff[*c] = str[a];
		a++;
		*c += 1;
	}
	return (a);
}

/**
 *match_char - prints a charather
 *@myargs: the character
 *@mybuff: print buffer
 *@c: position on buffer
 *Return: number of characther
 */

int match_char(va_list myargs, char *mybuff, int *c)
{
	if (*c >= 1022 || mybuff[*c] == '\n')
	{
		write(1, mybuff, (*c + 1));
		empty_buff(mybuff, c);
	}
	mybuff[*c] = va_arg(myargs, int);
	*c += 1;
	return (1);
}

/**
 *match_int - prints an integer
 *@myargs: the integer
 *@mybuff: print buffer
 *@c: position on print buffer
 *Return: number of characther
 */

int match_int(va_list myargs, char *mybuff, int *c)
{
	return (print_int(va_arg(myargs, int), 0, mybuff, c));
}

/**
 *empty_buff - empties a buffer
 *@mybuff: print buffer
 *@c: position in the buffer
 *Return: Nothing
 */

void empty_buff(char *mybuff, int *c)
{
	while (*c >= 0)
	{
		mybuff[*c] = '\0';
		*c -= 1;
	}
	*c = 0;
}
