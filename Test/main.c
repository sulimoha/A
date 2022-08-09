#include <limits.h>
#include <stdio.h>
#include "main.h"
int main()
{
	int len;
	len = _printf("Let's try to printf a simple sentence.\n");
	_putchar('\n');
	_putchar('\n');
	_putchar('\n');
	_putchar('\n');
	_putchar('\n');
	_putchar('\n');
	_printf("Length:[%d]\n", len);
	_printf("Length:[%d, %i]\n", len, len);
	_putchar('\n');

	/*
	_printf("s", "Let's try to printf a simple sentence.\n");
	_printf("c", 'L');
	_putchar('\n');
	_printf("d", 0);
	_putchar('\n');
	_printf("d", -1234567);
	_putchar('\n');
	*/
	/*len2 = printf("Let's try to printf a simple sentence.\n");*/
       	/*printf("Length:[%d, %i]\n", len2, len2);*/
	/*_printf("Length:[%d, %i]\n", len, len);*/

	return (0);
}
