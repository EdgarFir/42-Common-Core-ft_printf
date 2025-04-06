#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

static int	ft_is_valid_con(const char *str)
{
	char *conv;
	
	conv = "cspdiuxX%";
	if (!str[0] || !str[1])
		return (0);
	if (str[0] == '%' && ft_strchr(conv, str[1]))
		return (1);
	return (0);
}

static void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_format_c(int c)
{
	char	*str;
	
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = (char)c;
	str[1] = '\0';
	return (str);
}

char	*ft_format_s(char *s)
{
	if (!s)
		return(ft_strdup("(null)"));
	return (ft_strdup(s));
}

size_t	ft_hexlen(long long hex)
{
	if (!hex)
		return (0);
	return 1 + (ft_hexlen(hex / 16));
}

void	ft_convert_base(unsigned long long n, char *base, char *converted, size_t size)
{	
	int base_len;

	base_len = ft_strlen(base);
	converted[size] = '\0';
	while (size--)
	{
		converted[size] = base[n % base_len];
		n /= base_len;
	}
}

char	*ft_format_p(void *p)
{
	long long	adr;
	size_t		adr_len;
	char		*hex;

	if (!p)
		return (ft_strdup(("(nil)")));
	adr = (unsigned long long)p;
	adr_len = ft_hexlen(adr);
	hex = (char *)malloc(sizeof(char) * (adr_len + 3));
	if (!hex)
		return (NULL);
	hex[0] = '0';
	hex[1] = 'x';
	ft_convert_base(adr, "0123456789abcdef", &hex[2], adr_len);
	return (hex);
}

char	*ft_format_xX(unsigned int n, char conversion)
{
	size_t	n_len;
	char	*x;

	n_len = ft_hexlen(n);
	x = (char *)malloc(sizeof(n_len + 1));
	if (!x)
		return (NULL);
	if (conversion == 'x')
		ft_convert_base(n, "0123456789abcdef", x, n_len);
	else
		ft_convert_base(n, "0123456789ABCDEF", x, n_len);
	return (x);

}

size_t	ft_ulen(unsigned int u)
{
	if (!u)
		return (0);
	return 1 + (ft_ulen(u / 10));
}	

char	*ft_format_u(unsigned int u)
{
	char	*u_str;
	size_t	u_len;

	u_len = ft_ulen(u);
	u_str = (char *)malloc(sizeof(char) * (u_len + 1));
	if (!u_str)
		return (NULL);
	ft_convert_base(u, "0123456789", u_str, u_len);
	return (u_str);
}

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
	// Percorrer a string
	while (str[i])
	{
		if (ft_is_valid_con(&str[i]))
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
	//printf("TOTAL: %i\n", total);
	return (total);
}


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