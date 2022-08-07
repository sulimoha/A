#include "main.h"
#include <limits.h>
#include <stdio.h>
#include "Test/101-print_number.c"
int main()
{
	int len;
	int len2;
	
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
       	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Length:[%d, %i]\n", len, len);
	print_number(len);
	print_number(len2);

	return (0);
}
