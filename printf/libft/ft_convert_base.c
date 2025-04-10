/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:43:00 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/10 00:02:32 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_base(unsigned long long n, char *b, char *conv, size_t s)
{
	int	base_len;

	base_len = ft_strlen(b);
	conv[s] = '\0';
	while (s--)
	{
		conv[s] = b[n % base_len];
		n /= base_len;
	}
}
