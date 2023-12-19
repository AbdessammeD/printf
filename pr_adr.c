/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_adr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:42:27 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/15 12:40:31 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adr_len(unsigned long long adr)
{
	if (!adr)
		return (0);
	return (1 + adr_len(adr / 16));
}

static void	print_hex(unsigned long long adr)
{
	char	c;

	if (adr >= 16)
	{
		print_hex(adr / 16);
		write (1, &HEX_LO[adr % 16], 1);
	}
	else
	{
		if (adr < 10)
		{
			c = adr + 48;
			write(1, &c, 1);
		}
		else
			write (1, &HEX_LO[adr], 1);
	}
}

int	pr_adr(va_list *args)
{
	unsigned long long	add;
	int					len;

	len = 0;
	add = va_arg(*args, unsigned long long);
	if (add)
	{
		len = write(1, "0x", 2);
		print_hex(add);
	}
	else
		len = write(1, "0x0", 3);
	len += adr_len(add);
	return (len);
}
