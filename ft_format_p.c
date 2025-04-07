/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:12:55 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/07 18:58:56 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_format_p(void *p)
{
	long long	adr;
	size_t		adr_len;
	char		*hex;

	if (!p)
		return (ft_strdup(("(nil)")));
	adr = (unsigned long long)p;
	adr_len = ft_hexlen(adr);
	hex = (char *)malloc(sizeof(char) * (adr_len + 3));
	if (!hex)
		return (NULL);
	hex[0] = '0';
	hex[1] = 'x';
	ft_convert_base(adr, "0123456789abcdef", &hex[2], adr_len);
	return (hex);
}