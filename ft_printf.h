/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:07:54 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/13 00:10:21 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>
#include <string.h>

# define HEX_LO "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		ft_printf(const char *fr, ...);

int		pr_char(va_list *args);
int		pr_str(va_list *args);
int		pr_adr(va_list *args);
int		pr_dec(va_list *args);
int		pr_uns_nbr(va_list *args);
int		pr_hex(va_list *args, char c);

#endif