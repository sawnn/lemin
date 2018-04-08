/*
** EPITECH PROJECT, 2018
** my_checker2
** File description:
** gaspacho andalou
*/

#include "my.h"

int	my_check_2(char *str, int *a, int *i)
{
	while (my_strncmp(str, "#", 1) == 0) {
		my_strncmp(str, "##start", 7) == 0 ? *a = 1 : 0;
		my_strncmp(str, "##end", 5) == 0 ? *a = 2 : 0;
		*i += 1;
		if (!str)
			return (84);
	}
	return (0);
}

int	my_check_3(char *str, first_end *first)
{
	if (count_space(str) == 1 && check_nb(str) != NULL);
	else
		put_links_room(first, str);
	return (0);
}

int	check_comment2(char *str, int *a, int *i)
{
	if (*a == 1 && str) {
		my_strncmp(str, "#", 1) == 0
			&& my_strncmp(str, "##", 2) == 1
			? *i += 1 : 0;
		if (count_space(str) != 3 || check_room(str) == NULL)
			return (84);
		*a = 0;
	}
	return (0);
}

int	check_room_link2(char *str, room_s *room, room_s *tmp)
{
	char	*name = NULL;
	char	*link = NULL;

	if (count_space(str) == 1 && check_nb(str) != NULL);
	else if (count_space(str) == 1 && my_strncmp(str, "#", 1) == 1) {
		name = get_room(str);
		link = get_link(str);
		while (tmp->next && my_strcmp(tmp->name, name) == 0)
			tmp = tmp->next;
		if (!tmp->next && my_strcmp(tmp->name, name) == 0)
			return (84);
		tmp = room;
		while (tmp->next && my_strcmp(tmp->name, link) == 0)
			tmp = tmp->next;
		if (!tmp->next && my_strcmp(tmp->name, link) == 0)
			return (84);
		tmp = room;
	}
	return (0);
}

char	*check_coordonne(char **tab, room_s *room, char *x, char *y)
{
	int	i = -1;
	int	ret = 0;
	room_s	*tmp = room;
	while (tab[++i]) {
		if (count_space(tab[i]) == 3) {
			y = word_nbr_nb(tab[i], 3);
			x = word_nbr_nb(tab[i], 2);
		}
		while (y && x && tmp->next) {
			(my_strcmp(tmp->x, x) == 1
			&& my_strcmp(tmp->y, y) == 1) ? ret += 1 : 0;
			tmp = tmp->next;
		}
		if (ret > 1)
			return (NULL);
		tmp = room;
		y = x = NULL;
		ret = 0;
	}
	return (tab[0]);
}
