/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:22:13 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/13 01:34:10 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static void ft_print_front_width(t_flags *flags, int width, int n)
{
	if (flags->zero && !flags->precision)
	{
		if (flags->space)
			ft_putchar(' ');
		if (n < 0)
			ft_putchar('-');
		else if (flags->pos_sign && n > 0)
			ft_putchar('+');
		ft_print_flag('0', width);
	}
	else if (flags->space && !flags->pos_sign)
	{
		ft_print_flag(' ', width + 1);
	}
	else
	{
		ft_print_flag(' ', width);
		if (n < 0)
			ft_putchar('-');
		else if (flags->pos_sign && n > 0)
			ft_putchar('+');
	}
}
static void	ft_print_nbr(int n)
{
	long long	n_long;

	n_long = n;
	if (n_long < 0)
	{
		ft_putnbr_base((unsigned long long)(-n_long), "0123456789", 10);
	}
	else
		ft_putnbr_base((unsigned long long)n_long, "0123456789", 10);
}

int ft_count_digits(int n, t_flags *flags)
{
	int digits;
	int	n_len;

	n_len = (int)ft_nbrlen(n);
	if (n_len >= flags->precision) // digits = 3
		digits = n_len;
	else
		digits = flags->precision;
	if ((flags->pos_sign) && n >= 0 || (n < 0))
		digits++;
	else
	{
		if (flags->space)
			digits++;
	}
	//printf("D: %i\n", digits);
	return (digits);
}

static int	calculate_width(int n, t_flags *flags)
{
	int width;
	int digits;
	int n_len;

	n_len = (int)ft_nbrlen(n);
	digits = ft_count_digits(n, flags);
	width = 0;
	if (flags->width > digits)
		width = flags->width - digits;
	//printf("W: %i\n", width);
	return (width);
}

int	ft_format_i_d(int n, t_flags *flags)
{
	int	width;
	int precision;

	width = 0;
	if (flags->width)
		width = calculate_width(n, flags);
	if (width > 0 && !flags->neg_sign)
		ft_print_front_width(flags, width, n);
	else
	{
		if (flags->space)
			ft_putchar(' ');
		if (n < 0)
			ft_putchar('-');
		else if (flags->pos_sign && n > 0)
			ft_putchar('+');
	}
	precision = (int)flags->precision - ft_nbrlen(n);
	if (n < 0)
		precision++;
	if (precision > 0)
		ft_print_flag('0', precision);
	ft_print_nbr(n);
	if (width && flags->neg_sign)
		ft_print_flag(' ', width);
	if (width > 0)
		return (width + ft_count_digits(n, flags) - 1);
	return (ft_count_digits(n, flags) - 1);
}
