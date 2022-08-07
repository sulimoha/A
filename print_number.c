#include <stdio.h>
#include "main.h"
#include "_putchar.c"
/**
 *print_number - print number
 *@n: int number to be printed using only _putchar
 * Return:void
*/
void print_number(int n)
{
	int pow = 1;
	int a;
	int b;
	int pV = 0;
	int firstDigit;
	int i;

	if (n >= 0 && n < 10)
	{
		_putchar(n + '0');
	}
	else if (n < 0 && n > -10)
	{
		_putchar('-');
		_putchar(((n * -1) + '0'));
	}
	else
	{
		a = n;
		if (a < 0)
		{
			a = -1 * a;
			_putchar(a +'0');
		}

		while (a >= 10)
		{
			a = a / 10;
			pV++;
			_putchar(pV + '0');
		}
		for (i = 0; i < pV; i++)
		{
			pow = pow * 10;
			_putchar(pow + '0');
		}
		b = a;
		while (b >= 10)
		{
			firstDigit = b / pow;
			if (n <= -10)
			{
				_putchar('-');
			}
			_putchar(firstDigit + '0');
			b = b % pow;
			pow = pow / 10;
			if (b < 10)
			{
				_putchar(b + '0');
			}
		}
	}
}
int main(void)
{
	print_number(154);
	return (0);
}
