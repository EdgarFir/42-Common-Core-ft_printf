/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:13:55 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/15 15:52:25 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_format_c(int c);
int		ft_printf(const char *str, ...);
int		ft_is_valid_conv(const char *str);
int		ft_format_s(char *s);
int		ft_format_p(void *p);
int		ft_format_x(unsigned int n, char conversion);
int		ft_format_u(unsigned int u);
int		ft_format_i_d(int n);
int		ft_putnbr_base(unsigned long long n, char *base_s, int base_i);
int		ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);

#endif