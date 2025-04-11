/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:23:57 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 11:52:00 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_is_valid_conv(const char *str)
{
	char	*conv;

	conv = "cspdiuxX%";
	if (ft_strchr(conv, str[1]))
		return (1);
	return (0);
}
