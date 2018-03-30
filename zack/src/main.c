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

void	print_data_of_connected_nodes(node_t *node)
{
	link_t	*tmp = node->link;

	printf("%s\n", node->name);
	while (tmp) {
		printf("%s\n", tmp->node->name);
		tmp = tmp->next;
	}
	free(tmp);
}

void	get_tab(char **tab)
{
	char	*s = NULL;
	int	i = 0;

	while ((s = get_next_line(0))) {
		tab[i] = s;
		i += 1;
	}
	free(s);
	tab[i] = NULL;
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

node_t	**list_to_node(first_end *list)
{
	node_t		**graph = NULL;
	info_room	*tmp = list->first;
	int		i = -1;
	char		*str = NULL;

	if ((graph = malloc(sizeof(node_t *) * length_list(list) + 1)) == NULL)
		return (NULL);
	while (tmp) {
		graph[++i] = my_graphdup(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	return (graph);
}

int	sp(char *str, int i)
{
	while (str[i] && str[i++] != ' ');
	return (i);
}

void	connect_rooms(node_t *node, node_t **graph, char *str, int idx)
{
	int	j = -1;
	int	i = 1;
	char	*name = NULL;

	if (!str) {
		printf("NULL\n");
		free(name);
		return;
	}
	while (i <= count_space(str) + 1) {
		while (graph[++j]) {
			if ((name = word_nbr_nb(str, i)) == NULL)
				return;
			if (name && my_strcmp(graph[j]->name, name) == 0) {
				//			printf("connect %s && %s\n", node->name, name);
				connect_nodes(node, graph[j]);
				graph[idx] = node;
			}
		}
		free(name);
		i += 1;
		j = -1;
	}
	//print_data_of_connected_nodes(graph[idx]);
	printf("end\n");
}

node_t	*build_my_graph(node_t **all_node, first_end *list)
{
	int		i = -1;
	info_room	*tmp = list->first;

	while (all_node[++i] != NULL) {
		printf("connecting for %s to %s...\n", all_node[i]->name, tmp->links_room);
		connect_rooms(all_node[i], all_node, tmp->links_room, i);
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
	info_room	*tmp = NULL;

	if ((list = malloc(sizeof(first_end))) == NULL)
		return (84);
	if ((tab = malloc(sizeof(char *) * 100000)) == NULL)
		return (0);
	get_tab(tab);
	my_checker(list, tab);
	all_node = list_to_node(list);
	start = build_my_graph(all_node, list);
	//printf("ici %s\n", all_node[1]->link->node->name);
	free(list);
	free(all_node);
	free(tab);
	return (0);
}
