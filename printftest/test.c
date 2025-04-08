#include "../libftprintf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void compare_with_ori(char *s, void *var)
{
	char buf1[100], buf2[100];
	int pipefd[2];
	int printf_r;
	int	ft_printf_r;

	pipe(pipefd); // cria um pipe
	int saved_stdout = dup(STDOUT_FILENO); // guarda o stdout

	dup2(pipefd[1], STDOUT_FILENO); // redireciona stdout para pipe

	// chamada para ft_printf (exemplo)
	if (var)
		ft_printf_r = ft_printf(s, var);
	else
		ft_printf_r = ft_printf(s);
	fflush(stdout); // certifica-se de que escreve no pipe
	close(pipefd[1]);

	read(pipefd[0], buf1, sizeof(buf1)); // lê o output da ft_printf
	dup2(saved_stdout, STDOUT_FILENO); // restaura stdout

	// Agora para printf
	pipe(pipefd);
	dup2(pipefd[1], STDOUT_FILENO);

	if (var)
		printf_r = printf(s, var);
	else
	{
		puts(s);
		printf_r = strlen(s);
	}
		

	fflush(stdout);
	close(pipefd[1]);

	read(pipefd[0], buf2, sizeof(buf2));
	buf2[strcspn(buf2, "\n")] = 0;
	dup2(saved_stdout, STDOUT_FILENO);


	printf("buf1: %s\n", buf1); // Saída de ft_printf
    printf("buf2: %s\n", buf2); // Saída de printf

	// Comparação
	int are_equal = 0;
	if (strcmp(buf1, buf2) == 0)
	{
		are_equal = 1;
		printf("\033[0;32mEQUAL!\033[0m\n, \nft_printf: %s\nprintf:    %s\n", buf1, buf2);
	}
	else
		printf("\033[0;31mNOT EQUAL:\033[0m\nft_printf: %s\nprintf:    %s\n", buf1, buf2);
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

	char *s = "ABC";
	compare_with_ori("NUMBERS: %s\n", s);
	ft_printf("NUMBERS: %s\n", s);
}