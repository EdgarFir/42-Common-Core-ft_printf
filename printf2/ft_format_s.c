/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:10:05 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 16:32:39 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_format_s(char *s, t_flags *flags)
{
	int	total;

	total = 0;
	if (!s)
		total = ft_putstr("(null)");
	else
		total = ft_putstr(s);
	return (total);
}
