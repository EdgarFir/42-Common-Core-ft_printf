/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:43:00 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/07 18:45:04 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_base(unsigned long long n, char *base, char *converted, size_t size)
{	
	int base_len;

	base_len = ft_strlen(base);
	converted[size] = '\0';
	while (size--)
	{
		converted[size] = base[n % base_len];
		n /= base_len;
	}
}