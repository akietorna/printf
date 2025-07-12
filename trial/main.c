#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    /**
     *char c = 'i';
     *char *str = "I am going to school";
     *
     *unsigned int ui;
     *void *addr;
     */

    len = _printf("%");
    len2 = printf("-1");
    if (len2 == len)
    {
	    _printf("success  %i  %i   \n", len, len2);
    }
    else
    {
	    printf("failure  %i  %i   \n", len, len2);
    }
    return (0);
}
