/*
** EPITECH PROJECT, 2018
** fill_struct_info.c
** File description:
** fill my struct with the info I have
*/

#include "my.h"

char	*get_link(char *str)
{
	char	*name = NULL;
	int	i = -1;
	int	a = 0;

	while (str[++i])
		if (str[i] == '-')
			break;
	name = malloc_for_word(i, name, str, '\0');
	i += 1;
	while (str[i]) {
		name[a] = str[i];
		i += 1;
		a += 1;
	}
	name[a] = 0;
	return (name);
}

char	*get_room(char *str)
{
	int	i = -1;
	int	a = 0;
	char	*name = NULL;

	name = malloc_for_word(0, name, str, '-');
	while (str[++i]) {
		if (str[i] == '-') {
			name[a] = 0;
			return (name);
		}
		name[a] = str[i];
		a += 1;
	}
	name[a] = 0;
	return (name);
}

int	checkcomment(char **str, int j)
{
	int i = -1;

	while (str[j][++i]) {
		if (str[j][i] == '#' && i == 0)
			return (1);
		if (str[j][i] == '#' && i != 0) {
			return (0);
		}
	}
	return (0);
}

void	my_checker(first_end *first, char **tab)
{
	int	i = 0;
	int	a = 0;
	int	nb_ant = 0;

	init(first);
	while ((checkcomment(tab, i)) == 1)
		i++;
	nb_ant = my_getnbr(tab[i]);
	while (tab[++i]) {
		while (my_strncmp(tab[i], "#", 1) == 0) {
			my_strncmp(tab[i], "##start", 7) == 0 ?	a = 1 : 0;
			my_strncmp(tab[i], "##end", 5) == 0 ? a = 2 : 0;
			i += 1;
			if (!tab[i])
				return;
		}
		if (count_space(tab[i]) == 3)
			put_in_list(first, tab[i], &a, nb_ant);
		else {
			if (count_space(tab[i]) == 1 && check_nb(tab[i]) != NULL);
			else
				put_links_room(first, tab[i]);
		}
	}
}
