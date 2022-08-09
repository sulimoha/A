#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int _printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	char * separator = "";
	va_list args;
	c_s conv_specifiers[] = {
		{"c", _print_char},
		{"d", _print_int},
		{"i", _print_int},
		{"s", _print_char_ptr}
	};
	va_start(args, format);
	while (format != NULL && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *conv_specifiers[j].specifier)
			{
				conv_specifiers[j].f(separator, args);
					/*separator = ", ";*/
					separator = "";
			}
			j++;
		}
		i++;
	}
	va_end(args);
	return(i);
}
void _print_char(char *separator, va_list args)
{
	int i = 0;
	char c = va_arg(args, int);

	while (separator != NULL && separator[i])
	{
		_putchar(separator[i]);
		i++;
	}
		_putchar(c);
}
void _print_char_ptr(char *separator, va_list args)
{
	int i = 0;
	int j = 0;
	char *s= va_arg(args, char *);
	while (separator != NULL && separator[i])
	{
		_putchar(separator[i]);
		i++;
	}
	while (s && s[j])
	{
		_putchar(s[j]);
		j++;
	}
	
}

void _print_int(char *separator, va_list args)
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
