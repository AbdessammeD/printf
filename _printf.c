#include "main.h"

/**
 * print_symbol - print %.
 * @args: arguments.
 *
 * Return: current lenght.
 */
int print_symbol(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
 * _printf - printf function.
 * @format: string.
 *
 * Return: lenght.
 */
int _printf(const char *format, ...)
{
	op op[] = {{"c", handle_char}, {"s", handle_string}, {"d", handle_numbers},
		{"i", handle_numbers},
		{"b", handle_binary},
		{"%", print_symbol},
		{NULL, NULL}};
	int i = 0, j = 0, len = 0;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			while (op[j].op)
			{
				if (format[i] == op[j].op[0])
					len += op[j].f(args);
				j++;
			}
		}
		else
		{
			write(1, format + i, 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
