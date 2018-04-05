/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"

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
	if ((tab = my_reader(tab)) == NULL)
		return (84);
	my_checker(list, tab);
	all_node = list_to_node(list);
	start = build_my_graph(all_node, list);
	print_tab(tab);
	find_path(start, all_node);
	free(list);
	free(all_node);
	free(tab);
	return (0);
}
