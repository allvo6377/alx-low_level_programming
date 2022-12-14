#include "main.h"

/**
 * print_alphabet_x10 - print a - z ten times
 *
 */

void print_alphabet_x10(void)

{
	int k;
	char l;

	for (k = 0; k < 10; k++)
	{
		for (l = 'a'; l <= 'z'; l++)
		{
			_putchar(l);
		}

		_putchar('\n');
	}

}
