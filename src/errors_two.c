/*
** EPITECH PROJECT, 2018
** errors_two.c
** File description:
** deuxième gestion d'erreurs du grand Dali
*/

#include "my.h"

int	check_line(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1) {
		i += str[i] == '-' ? 1 : 0;
		i += str[i] == ' ' ? 1 : 0;
		if (str[i] < '0' && str[i] > '9')
			return (-1);
	}
}

int	check_twocommand(char **tab)
{
	int	idx_tab = 0;
	int	idx_cop = 0;

	for (idx_tab = 0; tab[idx_tab]; idx_tab += 1)
		idx_cop += (strcompar(tab[idx_tab], "##")) == 1 ? 1 : 0;
	return (idx_cop == 2 ? 0 : -1);
}
/*
int	check_is_good(char **tab)
{
	int	i = 0;
	int	j = 0;

	for (i = 0; tab[i] != NULL; i += 1) {
		for (j = 0; tab[i][j]; j += 1) {
			if (tab[i][j] == '#')
				tutu;
			if (tab[i][j] == ' ')
				toto;
			if (tab[i][j] == '-')
				titi;
		}
	}
}

int	line_isgood(char *str)
{
	
}*/
