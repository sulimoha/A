#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int _printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	int m = 0;
	char * separator = "";
	va_list args;
	c_s conv_specifiers[] = {
		{"d", _print_number},
		{"i", _print_number}
	};

	va_start(args, format);

	while(format != NULL && format[m])
	{
		if (format[m] != '%')
		{
			_putchar(format[m]);
			m++;
		}
		else
		{
			j = 0;
			while (j < 2)
			{
				if (format[i] == *conv_specifiers[j].specifier)
				{
					conv_specifiers[j].f(separator, args);
					separator = ", ";
				}
				j++;
			}
			m++;
		}
		va_end(args);
	}
	return(i);
}
void _print_char(char *separator, va_list args)
{
	int i = 0;
	int j = 0;
	char c = va_arg(args, int);

	while (separator != NULL && separator[i])
	{
		_putchar(separator[i]);
		i++;
	}
	while (c)
	{
		_putchar(c + '0');
		j++;
	}
}
void _print_char_ptr(char *separator, va_list args)
{
	int i = 0;
	int j = 0;
	char *s = va_arg(args, char *);

	while (separator != NULL && separator[i])
	{
		_putchar(separator[i]);
		i++;
	}
	while (s && s[j])
	{
		_putchar(s[j] + '0');
		j++;
	}
}
void _print_number(char *separator, va_list args)
{
	int n = va_arg (args, int);
	int i = 0;


	while (separator != NULL && separator[i])
	{
		_putchar(separator[i]);
		i++;
	}
	print_number(n);
}
void print_number(int n)
{
	int d;

	if (n < 0)
	{
		n = n * -1;
		d  = n;
		_putchar('-');
	}
	d = d / 10;
	if (d != 0)
	{
		print_number(d);
	}
	_putchar(n % 10 + '0');
}
