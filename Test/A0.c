#include <stdlib.h>
#include "main.h"
int _printf(const char *format, ...)
{
	int i = 0;
	while(format != NULL && format[i])
	{
		_putchar(format[i]);
		i++;
	}
	return (i);
}