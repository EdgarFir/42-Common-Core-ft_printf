/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:21:23 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/05 22:21:42 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_p;
	size_t			i;

	s_p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s_p == (unsigned char)c)
			return (s_p);
		s_p++;
		i++;
	}
	return (NULL);
}
