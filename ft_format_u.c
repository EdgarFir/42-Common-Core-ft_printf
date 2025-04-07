/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:44 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/07 18:59:26 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_format_u(unsigned int u)
{
	char	*u_str;
	size_t	u_len;

	u_len = ft_ulen(u);
	u_str = (char *)malloc(sizeof(char) * (u_len + 1));
	if (!u_str)
		return (NULL);
	ft_convert_base(u, "0123456789", u_str, u_len);
	return (u_str);
}