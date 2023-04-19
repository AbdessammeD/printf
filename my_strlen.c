#include "main.h"

/**
 * my_strlen - get lenght of a string.
 * @s: string.
 *
 * Return: lenght.
 */
int my_strlen(char *s)
{
	int l = 0;

	if (s)
	{
		while (*s)
		{
			l++;
			s++;
		}
	}
	return (l);
}
