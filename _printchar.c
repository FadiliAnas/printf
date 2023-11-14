#include "main.h"
/**
 * print_char - a function that produces output according to a format.
 * @args: a character string.
 * Return: return number of characters printed.
*/
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}
