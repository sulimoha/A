#include <stdlib.h>
#include <stdio.h>
#include "main5.h"
int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	va_list args;
	c_s conv_specifiers[] = {
		{"%", _print_int},
		{"d", _print_int},
		{"i", _print_int},
		{"u", _print_int}
	};
	va_start(args, format);
	while (format != NULL && format[i])
	{
		if (format[i] != *conv_specifiers[0].specifier)
		{
			_putchar(format[i]);
		}
		else
		{
			for (j = 1; j < 4; j++)
			{
				if (format[i+1] == *conv_specifiers[j].specifier)
				{
					format++;
					conv_specifiers[j].f(args);
				}
			}
		}
		i++;
	}
	va_end(args);
	return(i);
}
void _print_char(va_list args)
{
		_putchar(va_arg(args, int));
}
void _print_char_ptr(va_list args)
{
	int j = 0;
	char *s= va_arg(args, char *);
	
	while (s && s[j])
	{
		_putchar(*s);
	}
	
}

void _print_int(va_list args)
{
	print_number(va_arg (args, int));
}
void print_number(int n)
{
	if (n == 0)
	{
		_putchar('0');
	}
	if (n < 0)
	{
		n = n * -1;
		_putchar('-');
	}
	if (n / 10)
	{
		print_number(n / 10);
	}
	_putchar((n % 10) + '0');
}
