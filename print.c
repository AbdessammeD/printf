#include "main.h"

/**
 * print - print appropriate value.
 * @c: character.
 * @args: arguments passed to function.
 *
 * Return: current lenght.
 */
int print(char c, va_list args)
{
	int l = 0, integer, binary;
	char cha, *str;

	if (c == '%')
	{
		l++;
		write(1, "%", 1);
	}
	else if (c == 'c')
	{
		cha = va_arg(args, int);
		l++;
		write(1, &cha, 1);
	}
	else if (c == 's')
	{
		str = va_arg(args, char *);
		l++;
		write(1, str, my_strlen(str));
	}
	else if (c == 'd' || c == 'i')
	{
		integer = va_arg(args, int);
		l += print_number(integer);
	}
	else if (c == 'b')
	{
		binary = va_arg(args, int);
		l += print_binary(binary);
	}
	return (l);
}
