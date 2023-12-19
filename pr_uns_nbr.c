/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_uns_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:21 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/19 22:31:41 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	nbr_len(unsigned int nbr)
{
	if (!nbr)
		return (0);
	return (1 + nbr_len(nbr / 10));
}

static void	put_nbr(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
		return ;
	}
	else
	{
		put_nbr(n / 10);
		put_nbr(n % 10);
	}
}

int	pr_uns_nbr(va_list *args)
{
	unsigned int	nbr;
	int				len;

	nbr = va_arg(*args, unsigned int);
	if (!nbr)
		len = write(1, "0", 1);
	else
	{
		put_nbr(nbr);
		len = nbr_len(nbr);
	}
	return (len);
}
