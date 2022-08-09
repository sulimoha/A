#include "main.h"
/**
 *  _isdigit - entry point
 * @c: input charachter
 *
 * Return: 1 if c is upper case and 0 if it is not
*/

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
