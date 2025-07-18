#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 *match_pointer - prints a pointer
 *@myargs: arguments
 *@mybuff: print buffer
 *@c: position on the buffer
 *Return: length of the pointer
 */

int match_pointer(va_list myargs, char *mybuff, int *c)
{
	int a = 0;
	void *ptr = va_arg(myargs, void *);
	unsigned long int myptr;

	if (ptr == NULL)
	{
		return (-1);
	}
	myptr = (unsigned long)ptr;
	if (*c >= 1023)
	{
		write(1, mybuff, *c);
		empty_buff(mybuff, c);
	}
	mybuff[*c] = '0';
	*c += 1;
	a++;
	if (*c >= 1023)
        {
                write(1, mybuff, *c);
                empty_buff(mybuff, c);
        }
	mybuff[*c] = 'x';
	*c += 1;
	a++;
	a += print_pointer(myptr, 0, mybuff, c);
	return (a);
}
