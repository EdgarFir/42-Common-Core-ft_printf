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
	ft_printf("|%+5d|\n", value);

	printf("\n17. \"%% 1.5d\" (0 ignorado)\n");
	printf("|% 1.5d|\n", value);
	ft_printf("|% 1.5d|\n", value);

	printf("\n18. \"%%-.5d\"\n");
	printf("|%-.5d|\n", value);
	ft_printf("|%-.5d|\n", value);

	printf("\n19. \"%%+5.1d\"\n");
	printf("|%+5.1d|\n", value);
	ft_printf("|%+5.1d|\n", value);

	printf("\n20. \"%%-+8.3d\" (0 ignorado)\n");
	printf("|%-+8.3d|\n", value);
	ft_printf("|%-+8.3d|\n", value);

	printf("\n21. \"%%0 5d\" (0 ignorado)\n");
	printf("|%0 5d|\n", value);
	ft_printf("|%0 5d|\n", value);
}

void test_p()
{
	int x = 42;
    void *ptr = &x;

    printf("\n01. \"%%p\"\n");
    printf("|%p|\n", ptr);
    ft_printf("|%p|\n", ptr);

    printf("\n02. \"%%20p\" (width)\n");
    printf("|%20p|\n", ptr);
    ft_printf("|%20p|\n", ptr);

    printf("\n03. \"%%-20p\" (left align)\n");
    printf("|%-20p|\n", ptr);
    ft_printf("|%-20p|\n", ptr);

    printf("\n04. \"%%020p\" (zero-padding — ignorado)\n");
    printf("|%20p|\n", ptr);
    ft_printf("|%020p|\n", ptr);

    printf("\n05. \"%%.10p\" (precision — ignorado ou mal interpretado)\n");
    printf("|%p|\n", ptr);
    ft_printf("|%.10p|\n", ptr);

    printf("\n06. \"%%+p\" (ignored)\n");
    printf("|%p|\n", ptr);
    ft_printf("|%+p|\n", ptr);

    printf("\n07. \"%% p\" (space — ignored)\n");
    printf("|%p|\n", ptr);
    ft_printf("|% p|\n", ptr);

    printf("\n08. \"%%#p\" (hash — ignored)\n");
    printf("|%p|\n", ptr);
    ft_printf("|%#p|\n", ptr);

    printf("\n09. \"%%-#020.10p\" (combo — só '-' e width têm efeito)\n");
    printf("|%-20p|\n", ptr);
    ft_printf("|%-#020.10p|\n", ptr);

	void *p = NULL;
	printf("\n09. \"%%p\" (NULO)\n");
    printf("|%p|\n", p);
    ft_printf("|%p|\n", p);

}

void test_s()
{
	char *str = "Olá, mundo!";

    printf("\n01. \"%%s\" (sem flags)\n");
    printf("|%s|\n", str);
    ft_printf("|%s|\n", str);

    printf("\n02. \"%%15s\" (largura à direita)\n");
    printf("|%15s|\n", str);
    ft_printf("|%15s|\n", str);

    printf("\n03. \"%%-15s\" (largura à esquerda)\n");
    printf("|%-15s|\n", str);
    ft_printf("|%-15s|\n", str);

    printf("\n04. \"%%.5s\" (precisão: max 5 chars)\n");
    printf("|%.5s|\n", str);
    ft_printf("|%.5s|\n", str);

    printf("\n05. \"%%15.5s\" (largura 15 + precisão 5)\n");
    printf("|%15.5s|\n", str);
    ft_printf("|%15.5s|\n", str);

    printf("\n06. \"%%-15.5s\" (alinhamento à esquerda + precisão)\n");
    printf("|%-15.5s|\n", str);
    ft_printf("|%-15.5s|\n", str);

    printf("\n07. \"%%015s\" (zero-padding — ignorado)\n");
    printf("|%15s|\n", str);
    ft_printf("|%015s|\n", str);

    printf("\n08. \"%%+s\" (plus — ignorado)\n");
    printf("|%s|\n", str);
    ft_printf("|%+s|\n", str);

    printf("\n09. \"%% s\" (espaço — ignorado)\n");
    printf("|%s|\n", str);
    ft_printf("|% s|\n", str);

    printf("\n10. \"%%#s\" (hash — ignorado)\n");
    printf("|%s|\n", str);
    ft_printf("|%#s|\n", str);

	printf("\n11. \"%%10.10s\" (precisao > largura)\n");
    printf("|%20.50s|\n", str);
    ft_printf("|%20.50s|\n", str);

	printf("\n12. \"%%-20.10s\" (Combinacao das flags possiveis)\n");
    printf("|%-20.50s|\n", str);
    ft_printf("|%-20.50s|\n", str);

	char *s = NULL;
	printf("\n13. \"%%-20.50s\" (String nula)\n");
    printf("|%-20.50s|\n", s);
    ft_printf("|%-20.50s|\n", s);
}

// U
void test_u()
{
	unsigned int value = 123456;

    printf("\n01. \"%%u\" (sem flags)\n");
    printf("|%u|\n", value);
    ft_printf("|%u|\n", value);

    printf("\n02. \"%%10u\" (largura à direita)\n");
    printf("|%10u|\n", value);
    ft_printf("|%10u|\n", value);

    printf("\n03. \"%%-10u\" (alinhamento à esquerda)\n");
    printf("|%-10u|\n", value);
    ft_printf("|%-10u|\n", value);

    printf("\n04. \"%%010u\" (zero-padding)\n");
    printf("|%010u|\n", value);
    ft_printf("|%010u|\n", value);

    printf("\n05. \"%%.8u\" (precisão: 8 dígitos)\n");
    printf("|%.8u|\n", value);
    ft_printf("|%.8u|\n", value);

    printf("\n06. \"%%10.8u\" (largura + precisão)\n");
    printf("|%10.8u|\n", value);
    ft_printf("|%10.8u|\n", value);

    printf("\n07. \"%%-10.8u\" (alinhado à esquerda com precisão)\n");
    printf("|%-10.8u|\n", value);
    ft_printf("|%-10.8u|\n", value);

    printf("\n08. \"%%+u\" (plus — ignorado)\n");
    printf("|%u|\n", value);
    ft_printf("|%+u|\n", value);

    printf("\n09. \"%% u\" (espaço — ignorado)\n");
    printf("|%u|\n", value);
    ft_printf("|% u|\n", value);

    printf("\n10. \"%%#u\" (hash — ignorado)\n");
    printf("|%u|\n", value);
    ft_printf("|%#u|\n", value);
}
// X
// d, i

int main(void)
{
	//test_percent();
	printf("\n");
	//test_c();
	printf("\n");
	test_d_i();
	printf("\n");
	//test_p();
	printf("\n");
	//test_s();
	printf("\n");
	//test_u();

	return 0;
}