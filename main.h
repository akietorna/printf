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
	int (*print)(va_list, char *mybuff, int *c);
} def_func;


int print_pointer(unsigned long int num, int len, char *mybuff, int *c);
int match_pointer(va_list myargs, char *mybuff, int *c);
int match_big_string(va_list myargs, char *mybuff, int *c);
void *_calloc(unsigned int num, unsigned int size);
void empty_buff(char *mybuff, int *c);
int _printf(const char *format, ...);
int match_string(va_list myargs, char *mybuff, int *c);
int match_char(va_list myargs, char *mybuff, int *c);
int match_int(va_list myargs, char *mybuff, int *c);
int _strlen(char *s);
int print_int(int num, int len, char *mybuff, int *c);
void _putchar(char c);
void special_cases(const char *format, int *total, int a,
		   int status, char *mybuff, int *c);
int print_bin(unsigned int num, int len, char *mybuff, int *c);
int print_hex(unsigned int num, int len, char *mybuff, int *c);
int print_hex_big(unsigned int num, int len, char *mybuff, int *c);
int print_oct(unsigned int num, int len, char *mybuff, int *c);
int print_unint(unsigned int num, int len, char *mybuff, int *c);
int match_bin(va_list myargs, char *mybuff, int *c);
int match_hex(va_list myargs, char *mybuff, int *c);
int match_oct(va_list myargs, char *mybuff, int *c);
int match_unint(va_list myargs, char *mybuff, int *c);
int match_hex_big(va_list myargs, char *mybuff, int *c);
extern def_func printer[];

#endif
