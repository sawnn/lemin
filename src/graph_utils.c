/*
** EPITECH PROJECT, 2018
** graph utils
** File description:
** gaspacho andalou
*/

#include "my.h"

int	sp(char *str, int i)
{
	while (str[i] && str[i++] != ' ');
	return (i);
}

int	len_tab(node_t **tab)
{
	int	i = -1;

	while (tab[++i]);
	return (i);
}

node_t	**list_to_node(first_end *list)
{
	node_t		**graph = NULL;
	info_room	*tmp = list->first;
	int		i = -1;

	if ((graph = malloc(sizeof(node_t *) * length_list(list) + 1)) == NULL)
		return (NULL);
	while (tmp) {
		graph[++i] = my_graphdup(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	return (graph);
}

node_t	*my_graphdup(info_room *list)
{
	node_t	*tmp = NULL;

	if ((tmp = malloc(sizeof(node_t))) == NULL)
		return (NULL);
	if (!list)
		return (NULL);
	tmp->name = list->room_name;
	tmp->x = list->pos_x;
	tmp->y = list->pos_y;
	tmp->ant = list->ant;
	tmp->start = list->start;
	tmp->end = list->end;
	return (tmp);
}

int	length_list(first_end *list)
{
	info_room	*tmp = list->first;
	int		i = 0;

	while (tmp) {
		i += 1;
		tmp = tmp->next;
	}
	free(tmp);
	return (i);
}
