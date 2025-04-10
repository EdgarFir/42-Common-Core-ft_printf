/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:10:05 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/10 21:14:50 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_format_s(char *s)
{
	int	total;

	total = 0;
	if (!s)
		total = ft_putstr("(null)");
	else
		total = ft_putstr(s);
	return (total);
}
