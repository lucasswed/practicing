#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS 49	//TOTAL DE NUMEROS DO JOGO
#define MIN_APOSTA 6 //APOSTA MINIMA - 6 NUMEROS
#define NUM_LIN 7 //NUMERO DE NUMEROS APRESENTADOS POR LINHA NO BOLETIM

/*
 * Inicializa o gerador de numeros com um numero que depende da hora a que se executa a funcao
 */

void	inic_random(void)
{
	long	ultimate;
	time(&ultimate);
	srand((unsigned) ultimate);
}

/*
 * Inicializa o vetor de controlo dos numeros selecionados
 */

void	inic(int v[NUMS])
{
	int	i;

	for (i = 0; i < NUMS; i++)
		v[i] = 0;
}

/*
 * Le o numero de numeros a apostar. Aceita valores entre MIN_APOSTA e NUMS
 * Aceita o valor 0 para indicar que se quer terminar o programa
 */

int	ler_ns_apostar()
{
	int	n;

	do
	{
		printf("Quantos numeros quer apostar (0 - terminar): ");
		scanf("%d", &n);
	}
	while ((n < MIN_APOSTA || n > NUMS) && n != 0);
	return (n);
}

/*
 * Gera n numeros aleatorios e coloca a respetiva posicao no vetor
 * com o valor 1 que indica que esse numero ja foi selecionado
 */

void	gerar(int *v, int n)
{
	int	i;
	int	indice;

	for (i = 1; i <= n; i++)
	{
		indice = rand() % NUMS; //Devolve um numero aleatorio entre 0 e NUMS - 1
		if (v[indice] == 0) //Nao foi selecionado ainda
			v[indice] = 1;
		else //Ja tinha sido selecionado por isso volta se atras pra gerar outro aleatorio na i-esima posicao
			i--;
	}
}

/*
 *Apresenta o formato do boletim colocando XX nos numeros selecionados para a aposta
 */

void	apresentar(int res[])
{
	int	i;

	for (i = 0; i < NUMS; i++)
	{
		if (res[i] == 0)
			printf(" %2d", i + 1);
		else
			printf(" XX");
		if ((i + 1) % NUM_LIN == 0)
			putchar('\n');
	}
	putchar('\n');
}

int main(void)
{
	int	vetor[NUMS];
	int	n_nums;// Numero de numeros a jogar no jogo

	inic_random();
	while(1)
	{
		inic(vetor);
		if ((n_nums = ler_ns_apostar()) == 0)
			break;
		gerar(vetor, n_nums);
		apresentar(vetor);
	}
	return (0);
}
