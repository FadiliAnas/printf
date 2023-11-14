#include "main.h"

/**
 * print_string - write a string to the output
 * @args: input value
 * Return: return value of the string
*/
int print_string(va_list args)
{
	int count = 0, i = 0;
	char *ptr;

	ptr = va_arg(args, char *);
	if (ptr == NULL)
		ptr = "(null)";
		count = 6;
		write(1, ptr, 6);
	else
	{
		for (i = 0; ptr[i]; i++)
		{
			write(1, &ptr[i], 1);
			count += 1;
		}
	}
	return (count);
}
