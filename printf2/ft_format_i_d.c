/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:22:13 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 03:30:31 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static int	ft_cal_i_d_width(t_flags *flags, size_t len, int n)
{
	int	len_i;
	int	digits;
	int	precision;

	len_i = (int)len;
	digits = 0;
	if (n >= 0 && flags->pos_sign)
		digits++;
	if (flags->space && !flags->pos_sign && n < 0)
		digits++;
	return (flags->width - (len + digits));
}

static int	ft_print_i_d_front(t_flags *flags, int n)
{
	int total;

	total = 0;
	if (flags->zero && !flags->precision)
	{
		if (n >= 0)
		{
			if (flags->pos_sign)
				ft_print_flag('0', flags->width, 1, 0, '+');
			else
			{
				if (flags->space)
					ft_print_flag('0', flags->width - 1, 1, 0, ' ');
				else
					ft_print_flag('0', flags->width, 0, 0, 0);
			}
		}
		else
		{
			if (flags->space)
				ft_print_flag('0', flags->width + 1, 1, 0, '-');
			else
				ft_print_flag('0', flags->width, 1, 0, '-');
		}
	}
	else if (flags->space && !flags->pos_sign)
	{
		if (n < 0)
		{
			ft_print_flag(' ', flags->width + 1, 0, 0, 0);
			total += ft_putstr("-");
		}
		else
			ft_print_flag(' ', flags->width, 0, 0, 0);
	}
	else
	{
		if (flags->pos_sign && n >= 0)
			ft_print_flag(' ', flags->width, 0, 1, '+');
		else if (n < 0)
			ft_print_flag(' ', flags->width, 0, 1, '-');
		else
			ft_print_flag(' ', flags->width, 0, 0, 0);
	}
	return (total + flags->width);
}
static int	ft_print_n_prec(int n, int precision)
{
	int total;

	total = 0;
	if (precision > 0)
	{
		total = precision;
		ft_print_flag('0', precision, 0, 0, 0);
	}
	if (!n)
		total += (ft_putstr("0"));
	else if (n < 0)
		total += ft_putnbr_base((unsigned long long)-n, "0123456789", 10);
	else
		total += ft_putnbr_base((unsigned long long)n, "0123456789", 10);
	return (total);
}

static int ft_print_i_d(t_flags *flags, size_t len, int precision, int n)
{
	int total;

	total = 0;
	if (flags->width > 0 && !flags->neg_sign)
		total += ft_print_i_d_front(flags, n);
	else
	{
		if (flags->width <= 0 && flags->space && n >= 0)
			total += ft_putstr(" ");
		if (flags->pos_sign && n >= 0)
			total += ft_putstr("+");
		if (n <= 0)
			total += ft_putstr("-");
	}
	total += ft_print_n_prec(n, precision);
	if (flags->width > 0 && flags->neg_sign)
	{
		total += flags->width;
		ft_print_flag(' ', flags->width, 0, 0, 0);
	}
	return (total);
}

int	ft_format_i_d(int n, t_flags *flags)
{
	size_t	len;
	int		total;
	int		precision;
	int		signal;

	len = ft_nbrlen(n);
	precision = 0;
	signal = 0;
	if (flags->precision > 0 && flags->precision >= len)
	{
		if (n < 0)
			precision = (flags->precision - len) + 1;
		else
			precision = flags->precision - len;
	}
	flags->width = ft_cal_i_d_width(flags, len + precision, n);
	//printf("WIDTH: %i\n", flags->width);
	total += ft_print_i_d(flags, len, precision, n);
	return (total);
}