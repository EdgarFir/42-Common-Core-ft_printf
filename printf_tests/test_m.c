#include "../printf/libftprintf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
void compare_with_ori(char *origin, void *var, char *s, int n, unsigned int u)
{
	char buf1[100] = {0}, buf2[100] = {0};
	int pipefd[2];
	int printf_r;
	int ft_printf_r;

	int saved_stdout = dup(STDOUT_FILENO);

	// ---- FT_PRINTF ----
	pipe(pipefd);
	dup2(pipefd[1], STDOUT_FILENO);

	if (var)
		ft_printf_r = ft_printf(origin, var);
	else if (s)
		ft_printf_r = ft_printf(origin, s);
	else if (n)
		ft_printf_r = ft_printf(origin, n);
	else if (u)
		ft_printf_r = ft_printf(origin, u);
	else
		ft_printf_r = ft_printf(origin);

	fflush(stdout);
	close(pipefd[1]);

	int size1 = read(pipefd[0], buf1, sizeof(buf1) - 1);
	buf1[size1] = '\0';
	close(pipefd[0]);

	dup2(saved_stdout, STDOUT_FILENO);

	// ---- PRINTF ----
	pipe(pipefd);
	dup2(pipefd[1], STDOUT_FILENO);

	if (var)
		printf_r = printf(origin, var);
	else if (s)
		printf_r = printf(origin, s);
	else if (n)
		printf_r = printf(origin, n);
	else if (u)
		printf_r = printf(origin, u);
	else
	{
		puts(origin);
		printf_r = strlen(origin);
	}

	fflush(stdout);
	close(pipefd[1]);

	int size2 = read(pipefd[0], buf2, sizeof(buf2) - 1);
	buf2[size2] = '\0';
	close(pipefd[0]);

	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);

	// Comparação
	int are_equal = strcmp(buf1, buf2) == 0;

	if (are_equal)
	{
		printf("\033[0;32mEQUAL!\033[0m\nft_printf: %s\nprintf: %s\n", buf1, buf2);
	}
	else
	{
		printf("\033[0;31mNOT EQUAL:\033[0m\nft_printf: %s\nprintf: %s\n", buf1, buf2);
	}

	if (printf_r == ft_printf_r && are_equal)
	{
		printf("\033[0;32mCORRECT!\033[0m\n");
	}
	else
	{
		printf("\033[0;31mINCORRECT!\033[0m\n");
		printf("FT_PRINTF_SIZE: %i\nPRINTF_SIZE: %i\n", ft_printf_r, printf_r);
	}
}

int main()
{
	// Texto em vermelho

    //ft_printf("\033[0;31mEste texto está a vermelho!\033[0m\n");

    // Texto em verde
    //ft_printf("\033[0;32mEste está a verde!\033[0m\n");
	//ft_printf("\033[0;31mHELLO!\033[0m");

	int n = 41;
	compare_with_ori("NUMBERS: %i\n", 0, 0, n, 0);

	char s[] = "42";
	compare_with_ori("STRINGS: %s\n", 0, s, 0, 0);
}