#include <stdio.h>

void	gerador_comb(char str[], char array[9], int n, int curr)
{
	int	value;

	value = 0;
	while (value < 62)
	{
		array[curr] = str[value];
		if (curr == n - 1)
		{
			array[n] = '\0';
			printf("%s\n", array);
		}
		else
			gerador_comb(str, array, n, curr + 1);
		value++;
	}
}

	

int	main(void)
{
	char	array[9];
	int	n;
	int	curr;
	char	str[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	n = 1;
	curr = 0;
	while (n <= 8)
	{
		gerador_comb(str, array, n, curr);
		n++;
	}
	return (0);
}
