#include "main.h"

/**
 * _printf - printf function.
 * @format: string.
 *
 * Return: lenght.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int length = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else if (format[i])
				length += print(format[i], args);
		}
		else
		{
			length++;
			write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (length);
}
