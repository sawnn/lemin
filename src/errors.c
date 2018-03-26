/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** gestion d'erreur par le grand Dali
*/

#include "my.h"

int	checknumant(char **tab)
{
	int	ant = 0;

	for (ant = 0; tab[0][ant] != 0 && tab[0][ant] != 10; ant += 1)
		if (tab[0][ant] < 48 && tab[0][ant] > 57)
			return (-1);
	return (0);
}

int	check_starter(char **tab)
{
	int	idx_tab;
	int	idx_cop = 0;

	for (idx_tab = 0; tab[idx_tab] != NULL; idx_tab += 1) {
		if (str_compar(tab[idx_tab], "##start") == 1)
			idx_cop += 1;
	}
	return (idx_cop == 1 ? 0 : -1);
}
		
int	check_ender(char **tab)
{
	int	idx_tab;
	int	idx_cop = 0;

	for (idx_tab = 0; tab[idx_tab] != NULL; idx_tab += 1) {
		if (str_compar(tab[idx_tab], "##end") == 1)
			idx_cop += 1;
	}
	return (idx_cop == 1 ? 0 : 1);
}

int	check_nonb(char **tab)
{
	int	i = 0;

	for (i = 0; tab[i]; i += 1) {
		if (tab[i][0] != '#' && tab[i][1] < '0' && tab[i][1] > '9')
			return (84);
	}
}

int	check_gline(char **tab)
{
	int	i = 0;

	for (i = 0; tab[i]; i += 1) {
		i += tab[i][0] == '#' ? 1 : 0;
		if (check_line(tab[i]) == -1)
			return (-1);
	}
}
