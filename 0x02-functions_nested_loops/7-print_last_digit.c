#include "main.h"

/**
 * print_last_digit - prints the last digits of a number.
 * @n: the number in question.
 * Return: Value of the last digits.
 */

int print_last_digit(int n)

{
	int last_digit = n % 10;
	_putchar(last_digit)
	return (last_digit);
}
