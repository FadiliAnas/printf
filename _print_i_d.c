#include "main.h"
/**
 * print_i_d - write a integer to the output
 * @args: input value
 * Return: return value of the integer
*/
int print_i_d(va_list args)
{
	int value, i = 0;

	value = va_arg(args, int);
	if (value < 0)
	{
		write(1, "-", 1);
		i++;
		value = -value;
	}
	i += _countDigits(value);
	print_number(value);
	return (i);
}
