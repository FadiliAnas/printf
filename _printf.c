#include "main.h"



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

int _countDigits(int value)
{
	int count = 0;
	
	while (value != 0) 
	{
		value /= 10;
		count++;
	}
	return (count == 0) ? 1 : count;
}



int _printf(const char *format, ...)
{
	int i;
	int count = 0;
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


int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int print_string(va_list args)
{
	int count = 0, i = 0;
	char *ptr;

	ptr = va_arg(args, char *);
	if (ptr == NULL)
		ptr = "(null)";
	for (i = 0; ptr[i]; i++)
	{
		write(1, &ptr[i], 1);
		count += 1;
	}

	return (count);
}

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

	return i;
}

