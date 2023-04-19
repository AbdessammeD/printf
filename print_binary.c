#include "main.h"

/**
 * print_binary - convert an int to binary.
 * @binary: number to be converted.
 *
 * Return: current lenght.
 */
int print_binary(unsigned int binary)
{
	int l = 0;

	if (binary > 1)
	{
		print_binary(binary >> 1);
		l++;
	}
	if (binary & 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	return (l);
}
