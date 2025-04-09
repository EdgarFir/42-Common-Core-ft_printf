/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:28 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/09 01:27:34 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

static	int	ft_convert(char conversion, va_list lst)
{
	char	*format_str;

	if (conversion == 'c')
		format_str = ft_format_c(va_arg(lst, int));
	else if (conversion == '%')
		format_str = ft_format_c('%');
	else if (conversion == 's')
		format_str = ft_format_s(va_arg(lst, char *));
	else if (conversion == 'd' || conversion == 'i')
		format_str = ft_itoa(va_arg(lst, int));
	else if (conversion == 'p')
		format_str = ft_format_p(va_arg(lst, void *));
	else if (conversion == 'x' || conversion == 'X')
		format_str = ft_format_xX(va_arg(lst, unsigned int), conversion);
	else
		format_str = ft_format_u(va_arg(lst, unsigned int));
	if (!format_str)
		return (-1);
	ft_putstr(format_str);
	free(format_str);
	return (ft_strlen(format_str));
}

int ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		total;
	
	va_start(lst, str);
	i = 0;
	total = 0;
	while (str[i])
	{
		if (ft_is_valid_conv(&str[i]))
		{
			total += ft_convert(str[i + 1], lst);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			total++;
			i++;
		}
	}
	va_end(lst);
	return (total);
}
/*
int main()
{
	// Test % and c
	ft_printf("TEST CHAR AND %%: %% %c\n", 'A');
	ft_printf("TEST WITH PRINTF:\n");
	printf("TEST CHAR AND %%: %% %c\n\n", 'A');

	// s
	char *ss = NULL;
	ft_printf("TEST S: %s %s %s\n", "42", "", NULL);
	ft_printf("TEST WITH PRINTF:\n");
	printf("TEST S: %s %s %s\n\n", "42", "", ss);

	// p
	int i = 42;
	ft_printf("TEST P: %p %p\n", &i, NULL);
	ft_printf("TEST WITH PRINTF:\n");
	printf("TEST P: %p %p\n\n", &i, NULL);


	// i d u
	ft_printf("TEST I / D: %d %i %u\n", 42, 42, UINT_MAX);
	ft_printf("TEST WITH PRINTF:\n");
	printf("TEST I / D: %d %i %u\n\n", 42, 42, UINT_MAX);

	// x X
	ft_printf("TEST I / D: %x %X %x\n", 42, 42, -42);
	ft_printf("TEST WITH PRINTF:\n");
	printf("TEST I / D: %x %X %x\n\n", 42, 42, -42);
}
*/