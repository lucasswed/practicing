#include <stdio.h>

int	check_vitoria(char matriz[6][6])
{
	if (matriz[0][0] == matriz[0][2] && matriz[0][2] == matriz[0][4] && matriz[0][0] == 'X')
		return (1);
	if (matriz[0][0] == matriz[0][2] && matriz[0][2] == matriz[0][4] && matriz[0][0] == 'O')
		return (2);
	if (matriz[2][0] == matriz[2][2] && matriz[2][2] == matriz[2][4] && matriz[2][0] == 'X')
		return (1);
	if (matriz[2][0] == matriz[2][2] && matriz[2][2] == matriz[2][4] && matriz[2][0] == 'O')
		return (2);
	if (matriz[4][0] == matriz[4][2] && matriz[4][2] == matriz[4][4] && matriz[4][0] == 'X')
		return (1);
	if (matriz[4][0] == matriz[4][2] && matriz[4][2] == matriz[4][4] && matriz[4][0] == 'O')
		return (2);
	if (matriz[0][0] == matriz[2][0] && matriz[2][0] == matriz[4][0] && matriz[0][0] == 'X')
		return (1);
	if (matriz[0][0] == matriz[2][0] && matriz[2][0] == matriz[4][0] && matriz[0][0] == 'O')
		return (2);
	if (matriz[0][2] == matriz[2][2] && matriz[2][2] == matriz[4][2] && matriz[0][2] == 'X')
		return (1);
	if (matriz[0][2] == matriz[2][2] && matriz[2][2] == matriz[4][2] && matriz[0][2] == 'O')
		return (2);
	if (matriz[0][4] == matriz[2][4] && matriz[2][4] == matriz[4][4] && matriz[0][4] == 'X')
		return (1);
	if (matriz[0][4] == matriz[2][4] && matriz[2][4] == matriz[4][4] && matriz[0][4] == 'O')
		return (2);
	if (matriz[0][0] == matriz[2][2] && matriz[2][2] == matriz[4][4] && matriz[0][0] == 'X')
		return (1);
	if (matriz[0][0] == matriz[2][2] && matriz[2][2] == matriz[4][4] && matriz[0][0] == 'O')
		return (2);
	if (matriz[0][4] == matriz[2][2] && matriz[2][2] == matriz[4][0] && matriz[0][4] == 'X')
		return (1);
	if (matriz[0][4] == matriz[2][2] && matriz[2][2] == matriz[4][0] && matriz[0][4] == 'O')
		return (2);
	return (0);
}
