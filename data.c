#include <stdio.h>

int	ano_bissexto(int ano)
{
	if (ano % 100 == 0)
		return (0);
	else
	{
		if (ano % 4 == 0)
			return (1);
		else
			if (ano % 400 == 0)
				return (1);
		return (0);
	}
}

int	validacao_data(int dia, int mes, int ano)
{
	int	d;

	if (ano < 1 || dia < 1 || mes < 1 || mes > 12)
		return (0);
	d = 0;
	switch (mes)
	{
		case 2:
			if (ano_bissexto(ano) == 1)
				d = 29;
			else
				d = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d = 30;
			break;
		default:
			d = 31;
			break;
	}
	if (dia > d)
		return (0);
	return (1);
}

int	calculo(int dia, int mes, int ano)
{
	int k;
	int valor;

	if (mes == 1 || mes == 2)
	{
		mes += 12;
		ano -= 1;
	}
	k = dia + (2 * mes) + ((3 * (mes + 1)) / 5) + ano + (ano / 4) - (ano / 100) + (ano / 400) + 2;
	valor = k % 7;
	return (valor);
}

int	main(void)
{
	int ano;
	int mes;
	int dia;
	int dia_da_semana;

	printf("Digite uma data no formato dd/mm/aaaa: ");
	scanf(" %d/%d/%d", &dia, &mes, &ano);
	if (validacao_data(dia, mes, ano) == 1)
	{
		printf("A sua data e valida!\n");
		dia_da_semana = calculo(dia, mes, ano);
		switch (dia_da_semana)
		{
			case 0:
				printf("O dia da semana dessa data e sabado\n");
				break;
			case 1:
				printf("O dia da semana dessa data e domingo\n");
				break;
			case 2:
				printf("O dia da semana dessa data e segunda\n");
				break;
			case 3:
				printf("O dia da semana dessa data e terca\n");
				break;
			case 4:
				printf("O dia da semana dessa data e quarta\n");
				break;
			case 5:
				printf("O dia da semana dessa data e quinta\n");
				break;
			case 6:
				printf("O dia da semana dessa data e sexta\n");
				break;
		}
	}
	else
		printf("Data invalida!\n");
	return (0);
}
