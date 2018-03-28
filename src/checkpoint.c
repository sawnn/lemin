/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** partie de Dali
*/

#include "my.h"

int	my_checkpoint(first_end *first, char **tab)
{
	int	idx_check = 0;

	for (idx_check = 0; idx_check < 7; idx_check += 1) {
		if (my_ptab(idx_check, tab) == -1) {
			return (84);
		}
	}
	return (my_checker(first, tab));
}

int	my_ptab(int i, char **tab)
{
	ptab_t	check[8];

	check[0] = &checknumant;
	check[1] = &check_starter;
	check[2] = &check_ender;
	check[3] = &check_twocommand;
	check[4] = &check_nonb;
	check[5] = &check_gline;
	check[6] = &check_is_good;
	check[7] = NULL;
	return ((*check[i])(tab));
}
