/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** gestion d'erreur par le grand Dali
*/

#include "my.h"

char	*check_nb(char *tab)
{
	int	i = 0;

	while (tab[++i])
		if (tab[i] < 48 || tab[i] > 57)
			return (NULL);
	return (tab);
}

char	*check_line_two(char *tab, int a)
{
	while (tab[a]) {
		if (check_nb(tab) != NULL)
			return (tab);
		else if (tab[a] == '-' && tab[a + 1] != 0 && a != 0)
			break;
		else if (tab[a + 1] == 0 && tab[a] != '-')
			return (NULL);
		else
			a += 1;
	}
	return (tab);
}

char	*check_line(char **tab)
{
	int	i = -1;
	int	a = 0;

	while (tab[++i]) {
		while (my_strncmp(tab[i], "#", 1) == 0) {
			i = tab[i + 1] ? i + 1 : i;
			if (!tab[i + 1])
				break;
		}
		if (count_space(tab[i]) == 2 || count_space(tab[i]) > 3)
			return (NULL);
		else if (count_space(tab[i]) == 1 && !check_line_two(tab[i], a))
			return (NULL);
		a = 0;
	}
	return (tab[0]);
}

char	*check_room_2(char *str, room_s **tmp, int *i)
{
	char	*name = NULL;
	char	*link = NULL;

	if (count_space(str) == 1 && my_strncmp(str, "#", 1) == 1) {
		name = get_room(str);
		link = get_link(str);
		if ((my_strcmp((*tmp)->name, name) == 1) ^ (
				my_strcmp((*tmp)->name, link) == 1)) {
			*tmp = (*tmp)->next;
			*i = 1;
		}
	}
	return (name);
}

char	*check_room_alone(char **tab, room_s *room)
{
	room_s	*tmp = room;
	int	i = 1;
	char	*name = NULL;

	while (tmp->next && tab[++i]) {
		name = check_room_2(tab[i], &tmp, &i);
		if (!tab[i])
			return (NULL);
	}
	return (name);
}
