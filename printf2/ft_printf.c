/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:28 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/13 00:51:29 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	ft_convert(char conversion, va_list lst, t_flags *flags)
{
	int	total;

	total = 0;
	if (conversion == 'c')
		total = ft_format_c(va_arg(lst, int), flags);
	else if (conversion == '%')
		total = ft_format_c('%', flags);
	else if (conversion == 's')
		total = ft_format_s(va_arg(lst, char *), flags);
	else if (conversion == 'd' || conversion == 'i')
		total = ft_format_i_d(va_arg(lst, int), flags);
	else if (conversion == 'p')
		total = ft_format_p(va_arg(lst, void *), flags);
	else if (conversion == 'u')
		total = ft_format_u(va_arg(lst, unsigned int), flags);
	else
		total = ft_format_x(va_arg(lst, unsigned int), conversion, flags);
	return (total);
}

static t_flags *ft_create_struct(void)
{
	t_flags *new_struct;
	
	new_struct = (t_flags *)malloc(sizeof(t_flags));
	if (!new_struct)
		return (NULL);
	new_struct->neg_sign = 0;
	new_struct->zero = 0;
	new_struct->precision = 0;
	new_struct->prefix = 0;
	new_struct->space = 0;
	new_struct->pos_sign = 0;
	return (new_struct);
}

static int	ft_is_format(char c)
{
	char	*conv;

	conv = "cspdiuxX%";
	if (ft_strchr(conv, c))
		return (1);
	return (0);
}

static int	ft_is_flag(char c, t_flags *flags)
{
	char	*flags_lst;
	char	*conv;

	flags_lst = "-0# +";
	conv = ft_strchr(flags_lst, c);
	if (!conv)
		return (0);
	if (*conv == '-')
		flags->neg_sign = 1;
	else if (*conv == '0')
		flags->zero = 1;
	else if (*conv == '.')
		flags->precision = 1;
	else if (*conv == '#')
		flags->prefix = 1;
	else if (*conv == ' ')
		flags->space = 1;
	else
		flags->pos_sign = 1;
	return (1);
}

#include <stdio.h>
static int	ft_check_flags(const char *str, t_flags *flags)
{
	int total;
	int cal;
	int	n;

	total = 0;
	while (*str && ft_is_flag(*str, flags))
	{
		total++;
		str++;
	}
	cal = 0;
	n = ft_atoi(str);
	flags->width = n;
	cal = ft_nbrlen(n);
	str += cal;
	total += cal;
	if (*str && *str == '.')
	{
		n = ft_atoi(str + 1);
		flags->precision = n;
		cal = ft_nbrlen(n);
		total += cal + 1;
		str += cal + 1;
	}
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	t_flags *flags;
	int		i;
	int		total;
	int		chars_count;
	

	va_start(lst, str);
	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			flags = ft_create_struct();
			if (!flags)
				return (0);
			chars_count = ft_check_flags(&str[i], flags);
			i += chars_count;
			if (ft_is_format(str[i]))
			{
				//printf("%i\n", flags->neg_sign);
				total += ft_convert(str[i], lst, flags) + 1;
				i++;
			}
		}
		else
		{
			ft_putchar(str[i]);
			total++;
			i++;
		}
	}
	va_end(lst);
	return (total);
}
