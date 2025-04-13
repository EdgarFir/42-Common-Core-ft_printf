#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"


void test_percent()
{
	printf("------ Testes com '%%%%' (caractere de percentagem) ------\n");

	ft_printf("\n----- Flags with %% test: -----\n");
	ft_printf("1: |%%|\n"); // 1
	ft_printf("2: |%5%|\n"); // 2
	ft_printf("3: |%-5%|\n"); // 3
	ft_printf("4: |%0%|\n"); // 4
	ft_printf("5: |%05%|\n"); // 5
	ft_printf("6: |%-05%|\n"); // 6
	ft_printf("7: |%%%%|\n"); // 7
}

void test_c()
{
	char c = 'a';

    printf("----- Testes com %%c (caractere) -----\n\n");

    // Teste 1
    printf("1. \"%%c\"\n");
    printf("printf   : |%c|\n", c);
    ft_printf("ft_printf: |%c|\n\n", c);

    // Teste 2
    printf("2. \"%%5c\" (largura mínima 5)\n");
    printf("printf   : |%5c|\n", c);
    ft_printf("ft_printf: |%5c|\n\n", c);

    // Teste 3
    printf("3. \"%%-5c\" (alinhado à esquerda)\n");
    printf("printf   : |%-5c|\n", c);
    ft_printf("ft_printf: |%-5c|\n\n", c);

    // Teste 5
    printf("5. \"%%+c\" (flag '+' ignorada)\n");
    printf("printf   : |%c|\n", c);
    ft_printf("ft_printf: |%+c|\n\n", c);

    // Teste 6
    printf("6. \"%% c\" (flag espaço ignorada)\n");
    printf("printf   : |%c|\n", c);
    ft_printf("ft_printf: |% c|\n\n", c);

    // Teste 7
    printf("7. \"%%.c\" (precisão ignorada)\n");
    printf("printf   : |%c|\n", c);
    ft_printf("ft_printf: |%.c|\n\n", c);

    // Teste 8
    printf("8. \"%%-.5c\" (precisão ignorada, alinhado à esquerda)\n");
    printf("printf   : |%-5c|\n", c);
    ft_printf("ft_printf: |%-.5c|\n\n", c);
}

void test_d_i()
{
	int value = -42;
	printf("------ Testes de %%d e %%i com valor = %d ------\n", value);

	ft_printf("\n1. \"%%d\"\n");
	printf("|%d|\n", value);
	ft_printf("|%d|\n", value);

	printf("\n2. \"%%5d\"\n");
	printf("|%5d|\n", value);
	ft_printf("|%5d|\n", value);

	printf("\n3. \"%%-5d\"\n");
	printf("|%-5d|\n", value);
	ft_printf("|%-5d|\n", value);

	printf("\n4. \"%%05d\"\n");
	printf("|%05d|\n", value);
	ft_printf("|%05d|\n", value);

	printf("\n5. \"%%.5d\"\n");
	printf("|%.5d|\n", value);
	ft_printf("|%.5d|\n", value);

	printf("\n6. \"%%5.3d\"\n");
	printf("|%5.3d|\n", value);
	ft_printf("|%5.3d|\n", value);

	printf("\n7. \"%%+d\"\n");
	printf("|%+d|\n", value);
	ft_printf("|%+d|\n", value);

	printf("\n8. \"%% d\"\n");
	printf("|% d|\n", value);
	ft_printf("|% d|\n", value);

	printf("\n9. \"%%+5d\"\n");
	printf("|%+5d|\n", value);
	ft_printf("|%+5d|\n", value);

	printf("\n10. \"%% 5d\"\n");
	printf("|% 5d|\n", value);
	ft_printf("|% 5d|\n", value);

	printf("\n11. \"%%0+5d\"\n");
	printf("|%0+5d|\n", value);
	ft_printf("|%0+5d|\n", value);

	printf("\n12. \"%%-+5d\"\n");
	printf("|%-+5d|\n", value);
	ft_printf("|%-+5d|\n", value);

	printf("\n13. \"%%-5.3d\"\n");
	printf("|%-5.3d|\n", value);
	ft_printf("|%-5.3d|\n", value);

	printf("\n14. \"%%+08.5d\"\n");
	printf("|%+8.5d|\n", value);
	ft_printf("|%+08.5d|\n", value);

	printf("\n15. \"%%-05d\" (0 ignorado)\n");
	printf("|%-5d|\n", value);
	ft_printf("|%-05d|\n", value);

	printf("\n16. \"%%+ 5d\" (espaço ignorado)\n");
	printf("|%+5d|\n", value);
	ft_printf("|%+ 5d|\n", value);

	printf("\n17. \"%%0 10.5d\" (0 ignorado)\n");
	printf("|% 10.5d|\n", value);
	ft_printf("|%0 10.5d|\n", value);

	printf("\n18. \"%%-.5d\"\n");
	printf("|%-.5d|\n", value);
	ft_printf("|%-.5d|\n", value);

	printf("\n19. \"%%+5.1d\"\n");
	printf("|%+5.1d|\n", value);
	ft_printf("|%+5.1d|\n", value);

	printf("\n20. \"%%-+08.3d\" (0 ignorado)\n");
	printf("|%-+8.3d|\n", value);
	ft_printf("|%-+08.3d|\n", value);
}

int main(void)
{
	test_percent();
	printf("\n");
	test_c();
	printf("\n");
	test_d_i();
	return 0;
}