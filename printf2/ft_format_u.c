/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:44 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 01:24:12 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static size_t	ft_u_len(unsigned int u)
{
	if (!u)
		return (0);
	return (1 + ft_u_len(u / 10));
}

static int	ft_cal_u_width(t_flags *flags, size_t len)
{
	int	len_i;
	int	digits;
	int	precision;

	len_i = (int)len;
	digits = 0;
	if (flags->precision > 0 && flags->precision > len_i)
		digits = flags->precision;
	else
		digits = len_i;
	return (flags->width - digits);
}
static int ft_print_u_prec(unsigned int u, int precision)
{
	int total;

	total = 0;
	if (precision > 0)
	{
		total = precision;
		ft_print_flag('0', precision, 0, 0, 0);
	}
	if (!u)
		total += (ft_putstr("0"));
	else
		total += ft_putnbr_base(u, "0123456789", 10);
	return (total);

}

static int ft_print_u(t_flags *flags, size_t len, int precision, unsigned int u)
{
	int total;

	total = 0;
	if (flags->width > 0)
	{
		if (!flags->neg_sign)
		{
			if (flags->zero && !flags->precision) 
				ft_print_flag('0', flags->width, 0, 0, 0);
			else
				ft_print_flag(' ', flags->width, 0, 0, 0);
		}
		ft_print_u_prec(u, precision);
		if (flags->neg_sign)
			ft_print_flag(' ', flags->width, 0, 0, 0);
		return (total + flags->width);
	}
	return (ft_print_u_prec(u, precision));
}

int	ft_format_u(unsigned int u, t_flags *flags)
{	
	size_t	len;
	int		total;
	int		precision;

	len = ft_u_len(u);
	precision = 0;
	if (flags->precision > 0 && flags->precision > len)
		precision = flags->precision - len;
	flags->width = ft_cal_u_width(flags, len);
	total += ft_print_u(flags, len, precision, u);
	return (total);
}
