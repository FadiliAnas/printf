#include "main.h"

/**
 * print_number - a function
 * @n: input
 * Return: 0
 */
void print_number(int n)
{
	int number;
	int num = n;
	char signe;

	if (n < 0)
	{
		signe = '-';
		write(1, &signe, 1);

		num = -num;
	}
	if (num > 9)
	{
		print_number(num / 10);
	}
	number = (num % 10 + '0');
	write(1, &number, 1);
}
/**
 * _strlen - a function
 * @p: input value
 * Return: size
 */
int _strlen(char *p)
{
	int i = 0;

	while (*p != '\0')
	{
		i++;
		p++;
	}

	return (i);
}
/**
 *  _countDigits - a function that counts number of chars in an integer.
 * @value: input value.
 * Return: return the count.
 */
int _countDigits(int value)
{
	int count = 0;

	while (value != 0)
	{
		value /= 10;
		count++;
	}
	return ((count == 0) ? 1 : count);
}


/**
 * _printf - a function that produces output according to a format
 * @format: input
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	type ops[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_i_d},
		{'i', print_i_d},
	};
	va_start(args, format);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			i = 0;
			while (i < 3)
			{
				if (ops[i].character == *format)
				{
					count += ops[i].fp(args);
					break;
				}
				i++;
			}
			if (*format == '\0')
				return (-1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
