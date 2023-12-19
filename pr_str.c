/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:11 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/19 22:31:38 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
	{
		l++;
	}
	return (l);
}

int	pr_str(va_list *args)
{
	char	*str;
	size_t	len;

	str = va_arg(*args, char *);
	if (!str)
		len = write(1, "(null)", 6);
	else
	{
		len = ft_strlen(str);
		write(1, str, len);
	}
	return (len);
}
