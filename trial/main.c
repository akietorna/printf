#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("% d, %+i, %#o, %#X, %#x \n", 255, 255, 255, 255, 255);
	len2 = printf("% d, %+i, %#o, %#X, %#x \n", 255, 255, 255, 255, 255);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ. M: %d T: %d \n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
