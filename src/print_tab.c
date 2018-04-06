/*
** EPITECH PROJECT, 2018
** print_tab.c
** File description:
** print_tab.c
*/

#include "my.h"

char	*is_comment(char *str)
{
	int i = -1;

	while (str[++i])
		if (str[i] == '#' && i != 0 && str[i - 1] != '#') {
			str[i] = '\0';
			return (str);
		}
	return (str);
}

void	print_tab_two(char **tab, int *i)
{
	write(1, "\n#rooms\n", 8);
	while (tab[++*i]) {
		if (my_strncmp(tab[*i], "##", 2) == 0
			|| count_space(tab[*i]) == 3) {
			write(1, tab[*i], my_strlen(tab[*i]));
			write(1, "\n", 1);
		}
		else if (my_strncmp(tab[*i], "#", 1) == 0);
		else
			break;
	}
	write(1, "#tunnels\n", 9);
}

void	print_tab(char **tab)
{
	int	i = -1;

	write(1, "#number_of_ants\n", 16);
	while (tab[++i]) {
		if (my_strncmp(tab[i], "##", 2) == 1 &&
		my_strncmp(tab[i], "#", 1) == 0);
		else if (my_strncmp(tab[i], "##", 2) == 0) {
			my_printf("%s\n", tab[i]);
		} else {
			write(1, tab[i], my_strlen(tab[i]));
			break;
		}
	}
	print_tab_two(tab, &i);
	i -= 1;
	while (tab[++i]) {
		if (my_strncmp(tab[i], "#", 1) == 0);
		else
			my_printf("%s\n", tab[i]);
	}
}
