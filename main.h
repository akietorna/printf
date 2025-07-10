#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 *struct def_func - defines a match-make function
 *@arg: the charather
 *@print: the function
 */

typedef struct def_func
{
	char arg;
	int (*print)(va_list);
} def_func;


int _printf(const char *format, ...);
int match_float(va_list myargs);
int match_string(va_list myargs);
int match_char(va_list myargs);
int match_int(va_list myargs);
int _strlen(char *s);
int print_int(int num, int len);
void _putchar(char c);
void special_cases(const char *format, int *total, int a);
#endif
