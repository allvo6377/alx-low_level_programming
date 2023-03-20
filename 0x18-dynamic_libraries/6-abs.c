#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @h: THe int to be operated upon
 *
 * Return: returns an unsigneed int value to calling function
 */

int _abs(int h)
{
	if (h > 0)
	{
		return (h);
	}

	else
	{
		h *= -1;
		return (h);
	}
}
