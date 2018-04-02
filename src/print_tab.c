/*
** EPITECH PROJECT, 2018
** print_tab.c
** File description:
** print_tab.c
*/

#include "my.h"

void	print_tab_two(char **tab, int *i)
{
	while (tab[++*i]) {
		if (my_strncmp(tab[*i], "##", 2) == 0 || count_space(tab[*i]) == 3) {
			write(1, tab[*i], my_strlen(tab[*i]));
			write(1, "\n", 1);
		}
		else if (my_strncmp(tab[*i], "#", 1) == 0);
		else
			break;
	}
}

void	print_tab(char **tab)
{
	int	i = 0;

	write(1, "#number_of_ants\n", 16);
	write(1, tab[0], my_strlen(tab[0]));
	write(1, "\n#rooms\n", 8);
	print_tab_two(tab, &i);
	i -= 1;
	write(1, "#tunnel\n", 8);
	while (tab[++i]) {
		if (my_strncmp(tab[i], "#", 1) == 0);
		else {
			write(1, tab[i], my_strlen(tab[i]));
			write(1, "\n", 1);
		}
	}
}
