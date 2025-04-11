/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edfreder <edfreder@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:13:55 by edfreder          #+#    #+#             */
/*   Updated: 2025/04/11 17:45:51 by edfreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	neg_sign;
	int zero;
	int	precision;
	int prefix;
	int space;
	int pos_sign;
	int	width;
} t_flags;

int		ft_format_c(int c, t_flags *flags);
int		ft_printf(const char *str, ...);
int		ft_is_valid_conv(const char *str);
int		ft_format_s(char *s, t_flags *flags);
int		ft_format_p(void *p, t_flags *flags);
int		ft_format_x(unsigned int n, char conversion, t_flags *flags);
int		ft_format_u(unsigned int u, t_flags *flags);
int		ft_format_i_d(int n, t_flags *flags);
void	ft_print_spaces(int n);



#endif