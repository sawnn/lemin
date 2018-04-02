/*
** EPITECH PROJECT, 2018
** errors_two.c
** File description:
** deuxième gestion d'erreurs du grand Dali
*/

#include "my.h"

char	*check_room_name(room_s *room)
{
	room_s	*tmp2 = room;
	room_s	*tmp = room;
	int	a = 0;

	while (tmp->next) {
		while (tmp2->next) {
			if (my_strcmp(tmp->name, tmp2->name) == 1)
				a += 1;
			tmp2 = tmp2->next;
		}
		if (a != 1)
			return (NULL);
		tmp2 = room;
		tmp = tmp->next;
		a = 0;
	}
	return (room->name);
}

room_s	*put_list_room(room_s **room, char *tab)
{
	room_s	*tmp;

	if ((tmp = malloc(sizeof(room_s))) == NULL)
		return (NULL);
	tmp->name = word_nbr_nb(tab, 1);
	tmp->next = *room;
	*room = tmp;
	return (*room);
}

char	*check_link_same(char **tab)
{
	int	i = 0;
	char	*name = NULL;
	char	*link = NULL;

	while (tab[++i]) {
		if (count_space(tab[i]) == 1 && my_strncmp(tab[i], "#", 1) == 1) {
			name = get_room(tab[i]);
			link = get_link(tab[i]);
			if (my_strcmp(name, link) == 1)
				return (NULL);
		}
	}
	return (tab[0]);
}

char	*check_room_link(char **tab, room_s *room, int i)
{
	room_s	*tmp = room;
	char	*name = NULL;
	char	*link = NULL;

	while (tab[++i])
		if (count_space(tab[i]) == 1 && my_strncmp(tab[i], "#", 1) == 1) {
			name = get_room(tab[i]);
			link = get_link(tab[i]);
			while (tmp->next && my_strcmp(tmp->name, name) == 0)
				tmp = tmp->next;
			if (!tmp->next && my_strcmp(tmp->name, name) == 0)
				return (NULL);
			tmp = room;
			while (tmp->next && my_strcmp(tmp->name, link) == 0)
				tmp = tmp->next;
			if (!tmp->next && my_strcmp(tmp->name, link) == 0)
				return (NULL);
			tmp = room;
		}
	return (tab[0]);
}

char	*check_room(char *str)
{
	char	*name = NULL;
	int	i = -1;

	name = word_nbr_nb(str, 2);
	while (name[++i])
		if (name[i] < 48 || name[i] > 57)
			return (NULL);
	name = word_nbr_nb(str, 3);
	i = -1;
	while (name[++i])
		if (name[i] < 48 || name[i] > 57)
			return (NULL);
	return (str);
}
