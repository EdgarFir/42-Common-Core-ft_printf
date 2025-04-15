/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:10:05 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 03:27:43 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int ft_putnstr(char *s, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	ft_print_s(t_flags *flags, size_t len, char *s)
{
	int total;

	total = 0;
	if (flags->width > 0)
	{
		if (!flags->neg_sign)
			ft_print_flag(' ', flags->width, 0, 0, 0);
		if (!s)
			total = ft_putstr(("(null)"));
		else
			total = ft_putnstr(s, len);
		if (flags->neg_sign)
			ft_print_flag(' ', flags->width, 0, 0, 0);
		return (total + flags->width);
	}
	if (!s)
		total = ft_putstr(("(null)"));
	else
		total = ft_putnstr(s, len);
	return (total);
}

int	ft_format_s(char *s, t_flags *flags)
{
	int	total;
	int	str_len;
	size_t	len;

	total = 0;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (flags->precision > 0 && flags->precision < len)
		len = flags->precision;
	flags->width -= len;
	total += ft_print_s(flags, len, s);
	return (total);
}
