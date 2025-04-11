/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:28 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 18:01:41 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	ft_convert(char conversion, va_list lst, t_flags *flags)
{
	int	total;

	//printf("CONV: %c\n", conversion);
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
	// [flags][width][.precision][length][specifier]
	// Procurar flags
	while (*str && ft_is_flag(*str, flags))
	{
		//printf("HAS FLAG\n");
		total++;
		str++;
	}
	//printf("CHAR after flags: %c\n", *str);
	// Procurar width
	cal = 0;
	n = ft_atoi(str);
	flags->width = n;
	cal = ft_nbrlen(n);
	str += cal;
	total += cal;
	//printf("CHAR after flags: %c\n", *str);
	//printf("W: %i\n", flags->width);
	// Procurar precision
	if (*str && *str == '.')
	{
		flags->precision = 1;
		total++;
		str++;
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
			//printf("CHARS COUNT: %i\n", chars_count);
			i += chars_count;
			//printf("INDEX: %i\n", i);
			if (ft_is_format(str[i]))
			{
				//printf("FORMAT: %c\n", str[i]);
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
/*
#include <limits.h>
int main()
{
	
	/*
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