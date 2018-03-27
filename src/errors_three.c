/*
** EPITECH PROJECT, 2018
** lem-in
** File description:
** errors_three.c
*/

#include "my.h"

int	check_dasher(char *str)
{
	int	i = 0;
	int	idx_dash = 0;

	for (i = 0; str[i]; i += 1) {
		if ((str[i] != '-' && str[i] < '0')
		|| (str[i] != '-' && str[i] > '9'))
			return (-1);
		idx_dash += (str[i] == '-' ? 1 : 0);
		if (idx_dash > 1)
			return (-1);
	}
	return (0);
}
