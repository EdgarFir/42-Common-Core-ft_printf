#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	char c = 'a';
	//ft_printf("PRINT: \n");
	ft_printf("%5c\n", c);
	ft_printf("%-5c\n", c);
}