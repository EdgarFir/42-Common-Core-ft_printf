#include "../printf/ft_printf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "limits.h"

int main(void)
{
    int d = -123;
    int i = 456;
    unsigned int u = 3000000000;
    int hex = 48879;
    char *s = "Hello, World!";
    char *null_str = NULL;
    char c = 'A';
    void *p = &d;

    printf("----- Testing formats.. -----\n\n");

    // %d
    printf("1. %%d\n");
    printf("printf   : |%d|\n", d);
    ft_printf("ft_printf: |%d|\n\n", d);

    // %i
    printf("2. %%i\n");
    printf("printf   : |%i|\n", i);
    ft_printf("ft_printf: |%i|\n\n", i);

    // %u
    printf("3. %%u\n");
    printf("printf   : |%u|\n", u);
    ft_printf("ft_printf: |%u|\n\n", u);

    // %x
    printf("4. %%x\n");
    printf("printf   : |%x|\n", hex);
    ft_printf("ft_printf: |%x|\n\n", hex);

    // %X
    printf("5. %%X\n");
    printf("printf   : |%X|\n", hex);
    ft_printf("ft_printf: |%X|\n\n", hex);

    // %s
    printf("6. %%s (string normal)\n");
    printf("printf   : |%s|\n", s);
    ft_printf("ft_printf: |%s|\n\n", s);

    printf("7. %%s (string NULL)\n");
    printf("printf   : |%s|\n", null_str);
    ft_printf("ft_printf: |%s|\n\n", null_str);

    // %c
    printf("8. %%c\n");
    printf("printf   : |%c|\n", c);
    ft_printf("ft_printf: |%c|\n\n", c);

    // %p
    printf("9. %%p\n");
    printf("printf   : |%p|\n", p);
    ft_printf("ft_printf: |%p|\n\n", p);

    // %%
    printf("10. %%%%\n");
    printf("printf   : |%%|\n");
    ft_printf("ft_printf: |%%|\n\n");

    return 0;
}