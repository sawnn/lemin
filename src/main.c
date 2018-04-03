/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"

t_list	*create_list(t_list *list, int nb)
{
	t_list	*tmp = NULL;

	if ((tmp = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	tmp->nb = nb;
	tmp->next = list;
	list = tmp;
	return (tmp);
}

void	connect_nodes(node_t *node1, node_t *node2)
{
	link_t	*new = NULL;

	if ((new = malloc(sizeof(link_t))) == NULL)
		return;
	new->node = node2;
	new->next = node1->link;
	node1->link = new;
}

void	connect_rooms(node_t **graph, char *str, int idx)
{
	int	j = -1;
	int	i = 0;
	char	*name = NULL;

	if (!str) {
		free(name);
		return;
	}
	while (++i <= count_space(str) + 1) {
		name = word_nbr_nb(str, i);
		while (graph[++j]) {
			if (!name || name[0] == '\0')
				return;
			if (name && my_strcmp(name, graph[j]->name) == 1) {
				connect_nodes(graph[idx], graph[j]);
				connect_nodes(graph[j], graph[idx]);
				j = len_tab(graph) - 1;
			}
		}
		free(name);
		j = -1;
	}
}

node_t	*build_my_graph(node_t **all_node, first_end *list)
{
	int		i = -1;
	info_room	*tmp = list->first;

	while (all_node[++i] != NULL) {
		connect_rooms(all_node, tmp->links_room, i);
		tmp = tmp->next;
	}
	free(tmp);
	i = -1;
	while (all_node[++i]) {
		if (all_node[i]->start == 1)
			return (all_node[i]);
	}
	return (NULL);
}

int	main(UNU int ac, UNU char **av)
{
	first_end	*list = NULL;
	char		**tab = NULL;
	node_t		**all_node = NULL;
	node_t		*start = NULL;

	if ((list = malloc(sizeof(first_end))) == NULL)
		return (84);
	if ((tab = malloc(sizeof(char *) * 100000)) == NULL)
		return (0);
	if ((tab = my_reader(tab)) == NULL)
		return (84);
	my_checker(list, tab);
	all_node = list_to_node(list);
	start = build_my_graph(all_node, list);
	print_tab(tab);
	free(list);
	free(all_node);
	free(tab);
	return (0);
}
