/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:15 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/13 00:55:34 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_format_c(int c, t_flags *flags)
{
	if (flags->precision && !flags->width)
		flags->width = flags->precision;
	if (flags->width)
	{
		if (flags->neg_sign)
		{
			ft_putchar(c);
			ft_print_flag(' ', flags->width - 1);
		}
		else if (c == '%' && flags->zero)
		{
			ft_print_flag('0', flags->width - 1);
			ft_putchar(c);
		}
		else
		{
			ft_print_flag(' ', flags->width - 1);
			ft_putchar(c);
		}
		return (flags->width - 1);
	}
	ft_putchar(c);
	return (1);
}
