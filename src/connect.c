/*
** EPITECH PROJECT, 2018
** connect
** File description:
** gaspacho andalou
*/

#include "my.h"

void	connect_nodes(node_t *node1, node_t *node2)
{
	link_t	*new = NULL;

	if ((new = malloc(sizeof(link_t))) == NULL)
		return;
	new->node = node2;
	new->next = node1->link;
	node1->link = new;
}

int	my_connect(char *name, int idx, node_t **graph)
{
	int	j = -1;

	while (graph[++j]) {
		if (!name || name[0] == '\0')
			return (84);
		if (name && my_strcmp(name, graph[j]->name) == 1) {
			connect_nodes(graph[idx], graph[j]);
			connect_nodes(graph[j], graph[idx]);
			j = len_tab(graph) - 1;
		}
	}
	return (0);
}

void	connect_rooms(node_t **graph, char *str, int idx)
{
	int	i = 0;
	char	*name = NULL;

	if (!str) {
		free(name);
		return;
	}
	while (++i <= count_space(str) + 1) {
		name = word_nbr_nb(str, i);
		if (my_connect(name, idx, graph) == 84)
			return;
		free(name);
	}
}
