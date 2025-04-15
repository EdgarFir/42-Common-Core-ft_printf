/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:15 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 03:28:07 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_format_c(int c, t_flags *flags)
{
	int total;

	total = 1;
	if (flags->width)
	{
		total += flags->width - 1;
		if (!flags->neg_sign)
			ft_print_flag(' ', flags->width - 1, 0, 0, 0);
		ft_putchar(c);
		if (flags->neg_sign)
			ft_print_flag(' ', flags->width - 1, 0, 0, 0);
	}
	else
		ft_putchar(c);
	return (total);
}
