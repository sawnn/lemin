/*
** EPITECH PROJECT, 2018
** Lem-in
** File description:
** partie de Dali
*/

#include "my.h"

char	*check_ant(char **ant)
{
	int	a = -1;
	int	i = -1;

	while (ant[++a]) {
		if (my_strncmp(ant[a], "#", 1) == 0);
		else
			break;
	}
	while (ant[a][++i])
		if (ant[a][i] < 48 || ant[a][i] > 57)
			return (NULL);
	if (my_getnbr(ant[a]) <= 0)
		return (NULL);
	return (ant[a]);
}

int	comment(char *str, int *s, int *e, int *a)
{
	if (str)
		if (my_strncmp(str, "##", 2) == 0) {
			my_strncmp(str, "##start", 7) == 0 ? *s += 1 : 0;
			my_strncmp(str, "##end", 5) == 0 ? *e += 1 : 0;
			*a = 1;
			return (1);
		}
	return (0);
}

char	**check_comment(char **tab)
{
	int	i = -1;
	int	s = 0;
	int	e = 0;
	int	a = 0;

	while (tab[++i]) {
		my_strncmp(tab[i], "#", 1) == 0
			&& my_strncmp(tab[i], "##", 2) == 1
			? i += 1 : 0;
		comment(tab[i], &s, &e, &a) == 1 ? i += 1 : 0;
		if (check_comment2(tab[i], &a, &i) == 84)
			return (NULL);
		if (!tab[i])
			break;
	}
	if (s != 1 || e != 1)
		return (NULL);
	return (tab);
}

char	**check_two(char **tab, int ret, char *y, char *x)
{
	int	i = -1;
	room_s	*room = NULL;

	if ((room = malloc(sizeof(room_s))) == NULL)
		return (NULL);
	room->name = NULL;
	room->next = NULL;
	while (tab[++i])
		if (count_space(tab[i]) == 3)
			room = put_list_room(&room, tab[i]);
	i = 0;
	check_room_link(tab, room, i) == NULL ? ret = 84 : 0;
	check_link_same(tab) == NULL ? ret = 84 : 0;
	check_room_name(room) == NULL ? ret = 84 : 0;
	check_room_alone(tab, room) == NULL ? ret = 84 : 0;
	check_coordonne(tab, room, x, y) == NULL ? ret = 84 : 0;
	if (ret == 84)
		return (NULL);
	return (tab);
}

char	**my_checkpoint(char **tab)
{
	int	i = 1;
	int	ret = 0;
	char	*x = NULL;
	char	*y = NULL;

	if (check_line(tab) == NULL || check_ant(tab) == NULL
	    || check_comment(tab) == NULL)
		return (NULL);
	while (tab[i]) {
		if (count_space(tab[i]) == 3)
			check_room(tab[i]) == NULL ? ret = 84 : 0;
		i += 1;
	}
	return (check_two(tab, ret, y, x));
}
