/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:15:44 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 16:32:46 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_format_u(unsigned int u, t_flags *flags)
{
	if (!u)
		return (ft_putstr("0"));
	return (ft_putnbr_base(u, "0123456789", 10));
}
