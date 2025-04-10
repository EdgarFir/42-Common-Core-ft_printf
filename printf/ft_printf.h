#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int		ft_format_c(int c);
int		ft_printf(const char *str, ...);
int		ft_is_valid_conv(const char *str);
int		ft_format_s(char *s);
int		ft_format_p(void *p);
int		ft_format_x(unsigned int n, char conversion);
int		ft_format_u(unsigned int u);
int		ft_format_i_d(int n);

size_t	ft_hexlen(long long hex);
size_t	ft_ulen(unsigned int u);

#endif