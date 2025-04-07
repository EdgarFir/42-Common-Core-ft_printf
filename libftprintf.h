#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

char	*ft_format_c(int c);
int		ft_printf(const char *str, ...);
int		ft_is_valid_conv(const char *str);
char	*ft_format_s(char *s);
char	*ft_format_p(void *p);
char	*ft_format_xX(unsigned int n, char conversion);
char	*ft_format_u(unsigned int u);
size_t	ft_hexlen(long long hex);
size_t	ft_ulen(unsigned int u);

#endif