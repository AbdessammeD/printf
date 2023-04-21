#include "main.h"

/**
 * print_number - print a number.
 * @integer: the number to be printed.
 *
 * Return: current lenght.
 */
int print_number(int integer)
{
	int l = 0;
	char digit;

	if (integer == -2147483648)
	{
		l += 11;
		write(1, "-2147483648", 11);
		return (l);
	}
	if (integer < 0)
	{
		l++;
		write(1, "-", 1);
		integer *= -1;
	}
	if (integer > 9)
	{
		print_number(integer / 10);
	}
	l++;
	digit = '0' + (integer % 10);

	write(1, &digit, 1);
	return (l);
}
/**
 * handle_numbers - handle numbers.
 * @args: arguments.
 *
 * Return: current lenght.
 */
int handle_numbers(va_list args)
{
	int n = va_arg(args, int);
	int len = 0;

	len = print_number(n);
	return (len);
}
