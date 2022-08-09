#include <stdlib.h>
#include <stdio.h>
#include "main6.h"
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
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
				if (format[i + 1] == *conv_specifiers[j].specifier)
				{
					format++;
					conv_specifiers[j].f(conv_specifiers[j].specifier, args);
				}
			}
		}
		i++;
	}
	va_end(args);
	return (i);
}
/**
 * _print_char - function to print charactor
 * @specifier: percentage specifier argument
 * @args: charactor argument c
 *
 * Return: charactor when %c is true
 */
void _print_char(char *specifier, va_list args)
{
	char c = va_arg(args, int);

	(void) specifier;
	putchar(c);
}
/**
 * _print_char_ptr - function to print charactor pointer
 * @specifier: specifier argument of pointer type
 * @args: string argument
 *
 * Return: string when %s is true
 */
void _print_char_ptr(char *specifier, va_list args)
{
	int j = 0;
	int i = 0;
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
	if (*specifier == 'p')
	{
		while (s[i])
		{
			_putchar(s[i]);
			i++;
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
/**
 * _print_int - function to print integer
 * @args: valist argument
 * @specifier: ponter specifier for integer
 *
 * Return: an integer type
 */
void _print_int(char *specifier, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int n2;
	int i, j, m, count = 0;

	if (*specifier == 'u')
	{
		if (n != 0)
		{
			n = n * (-1);
		}
	}
	if (*specifier == 'o')
	{
		while (n / 8 != 0)
		{
			_putchar((n % 8) + '0');
			n = n / 8;

		}
	}

	if (*specifier == 'x')
	{
		if (n == 0)
			_putchar('0');
		for (n2 = n; n2 != 0; count++)
		{
			n2 = n2 / 16;
		}
		for (i = 0; n != 0; i++)
		{
			m = n % 16;
			if (m < 10)
			{
				specifier[i] = m + 10;
			}
			else
			{
				specifier[i] = m - 10 + 'a';
				n = n / 16;
			}
		}
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(specifier[m]);
			
		}
	} if (*specifier == 'X')
        {
		if (n == 0)
			_putchar('0');
		for (n2 = n; n2 != 0; count++)
		{
			n2 = n2 / 16;
		}
		for (i = 0; n != 0; i++)
		{
			m = n % 16;
			if (m < 10)
			{
				specifier[i] = m + 10;
			}
			else
			{
				specifier[i] = m - 10 + 'A';
				n = n / 16;
                        }
                }
                for (j = i - 1; j >= 0; j--)
                {
                        _putchar(specifier[m]);

                }
        }


	print_number(n);
}
/**
 * print_number - function to print number
 * @n: integer argument
 *
 * Return: number
 */
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
