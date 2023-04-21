#include "main.h"

/**
 * handle_string - print character.
 * @args: arguments.
 *
 * Return: 1.
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
