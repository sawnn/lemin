/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** gestion d'erreur par le grand Dali
*/

#include "my.h"

char	*check_line_two(char **tab, int a, int i)
{
	while (tab[i][a]) {
		if (tab[i][a] == '-' && tab[i][a + 1] != 0 && a != 0)
			break;
		else if (tab[i][a + 1] == 0 && tab[i][a] != '-')
			return (NULL);
		else
			a += 1;
	}
	return (tab[i]);
}

char	*check_line(char **tab)
{
	int	i = 0;
	int	a = 0;

	while (tab[++i]) {
		while (my_strncmp(tab[i], "#", 1) == 0) {
			if (tab[i + 1])
				i += 1;
			else
				return (tab[0]);
		}
		if (count_space(tab[i]) == 2)
			return (NULL);
		else if (count_space(tab[i]) == 1)
			if (check_line_two(tab, a, i) == NULL)
				return (NULL);;
		a = 0;
	}
	return (tab[0]);
}

char	*check_room_alone(char **tab, room_s *room)
{
	room_s	*tmp = room;
	int	i = 1;
	char	*name = NULL;
	char	*link = NULL;
	while (tmp->next && tab[++i]) {
		if (count_space(tab[i]) == 1 && my_strncmp(tab[i], "#", 1) == 1) {
			name = get_room(tab[i]);
			link = get_link(tab[i]);
			if ((my_strcmp(tmp->name, name) == 1) ^ (my_strcmp(tmp->name, link) == 1)) {
				tmp = tmp->next;
				i = 1;
			}
		}
		if (!tab[i])
			return (NULL);
	}
	return (name);
}
