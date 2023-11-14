#ifndef PRINT
#define PRINT

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void print_number(int n);
int _printf(const char *format, ...);
int _strlen(char *p);
int _countDigits(int value);
int print_char(va_list args);
int print_i_d(va_list args);
int print_string(va_list args);

/**
 * struct type - struct
 *
 * @character: input.
 * @fp: a function pointer.
*/

typedef struct type
{
	char character;
	int (*fp)(va_list);
} type;

#endif
