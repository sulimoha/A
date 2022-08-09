#include <stdlib.h>
#include <stdio.h>
#include "main6.h"
int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	va_list args;
	c_s conv_specifiers[] = {
		{"%", _print_int},
		{"d", _print_int},
		{"i", _print_int},
		{"u", _print_int},
		{"o", _print_int},
		{"c", _print_char},
		{"s", _print_char_ptr},
		{"%", _print_char_ptr}

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
			for (j = 1; j < 9; j++)
			{
				if (format[i+1] == *conv_specifiers[j].specifier)
				{
					format++;
					conv_specifiers[j].f(conv_specifiers[j].specifier, args);
				}
			}
		}
		i++;
	}
	va_end(args);
	return(i);
}
void _print_char(char *specifier, va_list args)
{
	char c = va_arg(args, int);

	(void) specifier;
	_putchar(c);
}
void _print_char_ptr(char *specifier, va_list args)
{
	int j = 0;
	int k = 0;
	char *s = va_arg(args, char*);

	if (*specifier == 's')
	{
		while (s[j])
		{
			_putchar(s[j]);
			j++;
		}
	}
	if (*specifier == '%')
	{
		while (s[k])
		{
			_putchar(s[k]);
			k++;
		}
	}
}

void _print_int(char *specifier, va_list args)
{
	int oct;
	int n = va_arg(args, int);

	if(*specifier == 'd')
	{
		print_number(n);
	}
	if(*specifier == 'i')
	{
		print_number(n);
	}
	if(*specifier == 'u')
	{
		if(n < 0)
		{
			n = n * (- 1);
		}
	print_number(n);
	}
	if(*specifier == 'o')
	{
		oct = n;
		while ((oct % 8) != 0)
		{
			_putchar((oct % 8) + '0');
			oct = oct / 8;
		}
	}
	
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
