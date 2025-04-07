/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:14:22 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/07 18:59:16 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_format_xX(unsigned int n, char conversion)
{
	size_t	n_len;
	char	*x;

	n_len = ft_hexlen(n);
	x = (char *)malloc(sizeof(n_len + 1));
	if (!x)
		return (NULL);
	if (conversion == 'x')
		ft_convert_base(n, "0123456789abcdef", x, n_len);
	else
		ft_convert_base(n, "0123456789ABCDEF", x, n_len);
	return (x);

}