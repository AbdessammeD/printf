/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:42:57 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/19 22:31:36 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	nbr_len(unsigned int nbr)
{
	if (!nbr)
		return (0);
	return (1 + nbr_len(nbr / 16));
}

static void	print_hex(unsigned int nbr, char c)
{
	char	chr;

	if (nbr >= 16)
	{
		print_hex(nbr / 16, c);
		if (c == 'x')
			write (1, &HEX_LO[nbr % 16], 1);
		else
			write (1, &HEX_UP[nbr % 16], 1);
	}
	else
	{
		if (nbr < 10)
		{
			chr = nbr + 48;
			write(1, &chr, 1);
		}
		else
		{
			if (c == 'x')
				write (1, &HEX_LO[nbr % 16], 1);
			else
				write (1, &HEX_UP[nbr % 16], 1);
		}
	}
}

int	pr_hex(va_list *args, char c)
{
	int	nbr;
	int	i;
	int	len;

	nbr = va_arg(*args, unsigned int);
	if (!nbr)
		len = write(1, "0", 1);
	else
	{
		print_hex(nbr, c);
		len = nbr_len(nbr);
	}
	return (len);
}
