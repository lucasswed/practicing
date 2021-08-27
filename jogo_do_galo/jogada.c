#include <stdio.h>

/*
 * Teste para ver se o espaco escolhido ja foi ocupado
 */

int	check_jogada(char matriz[6][6], int i, int j)
{
	if (matriz[i][j] == ' ')
		return (1);
	else
		return (0);
}

/*
 * Converte a jogada do usuario para os indices da matriz
 */

int	convert_jog(int i)
{
	int	a;

	if (i == 1)
		a = 0;
	else if (i == 2)
		a = 2;
	else if (i == 3)
		a = 4;
	else
		a = -1;
	return (a);
}

/*
 * Recebe a jogada do jogador
 */

void	jogada(char matriz[6][6], char jogador)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (j == -1 || i == -1)
	{
		printf("Digite a linha e a coluna do espaco que deseja ocupar: ");
		scanf(" %d %d", &i, &j);
		i = convert_jog(i);
		j = convert_jog(j);
		if (check_jogada(matriz, i, j))
		{
			if (jogador == 'X')
				matriz[i][j] = 'X';
			if (jogador == 'O')
				matriz[i][j] = 'O';
		}
		else
		{
			printf("Espaco ja ocupado, tente novamente!\n");
			i = -1;
			j = -1;
		}
	}
}
