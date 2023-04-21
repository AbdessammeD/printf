#include "main.h"

/**
 * handle_string - print string.
 * @args: arguments.
 *
 * Return: current lenght.
 */
int handle_string(va_list args)
{
	int i, len = 0;
	char *s = va_arg(args, char *);

	if (!s)
		s = "(null)";
	for (i = 0; s[i]; i++, len++)
		write(1, s + i, 1);
	return (len);
}
