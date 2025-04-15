/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:12:55 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/14 21:59:00 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t ft_hexlen(long long hex)
{
	if (!hex)
		return (0);
	else
		return (1 + ft_hexlen(hex / 16));
}

#include <stdio.h>

static int	print_p_width(t_flags *flags, unsigned long long adr)
{
	int total;

	total = 0;
	if (flags->width > 0)
	{
		if (!flags->neg_sign)
			ft_print_flag(' ', flags->width);
		if (!adr)
			total = ft_putstr(("(nil)"));
		else
			total = ft_putstr("0x") + ft_putnbr_base(adr, "0123456789abcdef", 16);
		if (flags->neg_sign)
			ft_print_flag(' ', flags->width);
		return (total + flags->width);
	}
	if (!adr)
		total = ft_putstr(("(nil)"));
	else
		total = ft_putstr("0x") + ft_putnbr_base(adr, "0123456789abcdef", 16);
	return (total);
}

int	ft_format_p(void *p, t_flags *flags)
{
	long long	adr;
	int			total;
	size_t		len;

	total = 0;
	adr = 0;
	if (!p)
		len = 5;
	else
	{
		adr = (unsigned long long)p;
		len = (int)ft_hexlen(adr) + 2;
	}
	flags->width -= len;
	total += print_p_width(flags, adr);
	return (total);
}
