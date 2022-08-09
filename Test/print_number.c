#include "main.h"
void print_number(int n)
{
	unsigned int d = n;

	if (n < 0)
	{
		n = n * -1;
		d = n;
		_putchar('-');
	}
	d = d / 10;
	if (d != 0)
	{
		print_number(d);
	}
	_putchar(n % 10 + '0');
}





