/*
** EPITECH PROJECT, 2018
** utils path 3
** File description:
** gaspacho andalou
*/

#include "my.h"

void	moves_2(int i, int **ant, char **tmp, PARAM)
{
	if (i != 0 && ant[i][0] != 0 && ant[i + 1][0] == 0) {
		ant[i + 1][0] = ant[i][0];
		ant[i][0] = 0;
		write_moves(ant[i + 1][0], tmp[i + 1]);
		check_space(ant, i, nbr_ant);
	}
	if (i == 0 && ant[i + 1][0] == 0 && ant[0][nbr_ant - 1] != -1) {
		ant[i + 1][0] = ant[i][++(*j)];
		ant[i][*j] = -1;
		write_moves(ant[i + 1][0], tmp[i + 1]);
		check_space(ant, i, nbr_ant);
	}
	if (i == nbr - 2 && ant[i + 1][0] != 0)
		ant[i + 1][0] = 0;
}
