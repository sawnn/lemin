/*
** EPITECH PROJECT, 2018
** find_path2
** File description:
** gaspacho andalou
*/

#include "my.h"

int	check_nbr_ant(int **ant, int nbr)
{
	int i = 0;

	while (++i < nbr)
		if (ant[i][0] != 0)
			return (1);
	return (0);
}

void	write_moves(int nbr, char *str)
{
	write(1, "P", 1);
	my_put_nbr(nbr);
	write(1, "-", 1);
	write(1, str, my_strlen(str));
}

int	check_first(int *ant, int nbr)
{
	int i = -1;

	while (++i < nbr)
		if (ant[i] != -1)
			return (1);
	return (0);
}

void	check_space(int **ant, int i, int nbr_ant)
{
	if (i > 1 && ant[i - 1][0] != 0)
		write(1, " ", 1);
	if (i == 1 && check_first(ant[0], nbr_ant) == 1)
		write(1, " ", 1);
}
