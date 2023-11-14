#include "main.h"

/**
 * print_i_d - write a integer to the output
 * @value: input value
 * Return: return value of the integer
*/
int print_i_d(int value)
{
	i = 0;

	if (value < 0)
	{
		i++;
	}
	i += _countDigits(value);
	print_number(value);
	return (i);
}
