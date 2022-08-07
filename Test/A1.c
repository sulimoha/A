#include <stdlib.h>
#include "main.h"
int _printf(const char *format, ...)
{
	int i = 0;
	while(format != NULL && format[i])
	{
		if (format[i] != "%")
		{
			_putchar(format[i]);
			i++;
		}
		else
		{
			i++;

			
	return (i);
}
