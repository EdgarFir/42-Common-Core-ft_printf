/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:22:13 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/10 21:13:34 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_format_i_d(int n)
{
	char		*base;
	long long	n_long;

	n_long = n;
	base = "0123456789";
	if (n < 0)
	{
		ft_putchar('-');
		return (1 + (ft_putnbr_base((unsigned long long)(-n_long), base, 10)));
	}
	return ((ft_putnbr_base((unsigned long long)n_long, base, 10)));
}
