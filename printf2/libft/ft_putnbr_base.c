/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:09:35 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/10 21:11:16 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long long n, char *base_s, int base_i)
{
	int	total;

	total = 0;
	if (n >= (unsigned long long)base_i)
		total += ft_putnbr_base(n / base_i, base_s, base_i);
	ft_putchar(base_s[n % base_i]);
	return (total + 1);
}
