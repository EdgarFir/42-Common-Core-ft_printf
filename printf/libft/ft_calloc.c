/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:57:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/05 22:05:27 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_to_aloc;
	void	*ptr;

	if (size != 0 && nmemb > (size_t)(-1) / size)
		return (NULL);
	mem_to_aloc = nmemb * size;
	ptr = malloc(mem_to_aloc);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, mem_to_aloc);
	return (ptr);
}
