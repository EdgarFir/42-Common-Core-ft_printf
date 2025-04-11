/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:15 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 18:00:42 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>
int	ft_format_c(int c, t_flags *flags)
{	
	int len;
	
	//printf("FORMAT: %c\n", (char)c);
	len = 1;
	if (flags->width)
	{
		//printf("W: %i\n", flags->width);
		len = flags->width - 1;
		if (flags->neg_sign)
		{
			//printf("C: %c", c);
			ft_putchar(c);
			ft_print_spaces(len);
		}
		else
		{
			ft_print_spaces(len);
			ft_putchar(c);
		}
		return (flags->width - 1);
	}
	else
	{
		ft_putchar(c);
	}
	return (len);
}
