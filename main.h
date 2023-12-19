/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lha <aait-lha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:07:54 by aait-lha          #+#    #+#             */
/*   Updated: 2023/12/19 22:31:19 by aait-lha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_LO "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		_printf(const char *format, ...);

int		pr_char(va_list *args);
int		pr_str(va_list *args);
int		pr_adr(va_list *args);
int		pr_dec(va_list *args);
int		pr_uns_nbr(va_list *args);
int		pr_hex(va_list *args, char c);

#endif