/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:16:30 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/03 17:18:54 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_p;
	unsigned char	*src_p;
	size_t			i;

	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	if (dest_p < src_p)
	{
		i = 0;
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_p[i] = src_p[i];
		}
	}
	return (dest);
}
