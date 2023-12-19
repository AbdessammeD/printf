/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:42 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/15 12:29:07 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	call_func(char c, va_list *args)
{
	int	len;

	if (c == 'c')
		len = pr_char(args);
	else if (c == 's')
		len = pr_str(args);
	else if (c == 'i' || c == 'd')
		len = pr_dec(args);
	else if (c == 'p')
		len = pr_adr(args);
	else if (c == 'X' || c == 'x')
		len = pr_hex(args, c);
	else if (c == 'u')
		len = pr_uns_nbr(args);
	else if (c == '%')
		len = write(1, &c, 1);
	return (len);
}

static int	check_format(const char *fr, va_list args)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (fr[i])
	{
		if (fr[i] == '%')
		{
			i++;
			if (!fr[i])
			{
				va_end(args);
				return (-1);
			}
			else if (ft_strchr("cspdixXu%", fr[i]))
				len += call_func(fr[i], &args);
		}
		else
			len += write(1, &fr[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fr, ...)
{
	va_list		args;
	int			len;
	int			i;

	if (!fr)
		return (-1);
	va_start(args, fr);
	len = check_format(fr, args);
	va_end(args);
	return (len);
}
