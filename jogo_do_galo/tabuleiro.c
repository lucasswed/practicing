#include <stdio.h>

void	jogada(char matriz[6][6], char jogador);

int	check_vitoria(char matriz[6][6]);

/*
 * Gera a matriz que vai ser o tabuleiro do jogo
 */

void	gerar_tabuleiro(char matriz[6][6])
{
	int	i;
	int	j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i % 2 != 0)
				matriz[i][j] = '-';
			else
			{
				if (j % 2 == 0)
					matriz[i][j] = ' ';
				else
					matriz[i][j] = '|';
			}
		}
	}
}
				
void	print_tabuleiro(char matriz[6][6])
{
	int	i;
	int	j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%c", matriz[i][j]);
		putchar('\n');
	}
}

int main(void)
{
	char	matriz[6][6];
	int	i;

	i = 0;
	gerar_tabuleiro(matriz);
	print_tabuleiro(matriz);
	while (i < 9)
	{
		printf("Jogador X\n");
		jogada(matriz, 'X');
		print_tabuleiro(matriz);
		if (i > 1 && check_vitoria(matriz))
			break;
		printf("Jogador O\n");
		jogada(matriz, 'O');
		print_tabuleiro(matriz);
		if (i > 1 && check_vitoria(matriz))
			break;
		i++;
	}
	if (check_vitoria(matriz) == 1)
		printf("O jogador X ganhou!\n");
	else if (check_vitoria(matriz) == 2)
		printf("O jogador O ganhou!\n");
	else
		printf("Empate!");
	return (0);
}
