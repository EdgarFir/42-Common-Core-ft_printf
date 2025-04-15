/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:20:12 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 01:50:30 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void ft_print_flag(int c, int len, int sign_before, int sign_after, char signal)
{
	//printf("LEN: %i\n", len);
	if (sign_before && signal)
		ft_putchar(signal);
	while (len--)
	{
		ft_putchar(c);
	}
	if (sign_after && signal)
		ft_putchar(signal);
}