#include "main.h"

/**
 * print_i_d - write a integer to the output
 * @value: input value
 * Return: return value of the integer
*/
int print_i_d(va_list args)
{
	int i = 0;
	int value = va_arg(args, int);

	if (value < 0)
	{
		i++;
	}
	i += _countDigits(value);
	print_number(value);
	return (i);
}
