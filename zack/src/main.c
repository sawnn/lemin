/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"

node_t	*create_node(int data)
{
	node_t	*tmp = NULL;

	if ((tmp = malloc(sizeof(node_t))) == NULL)
		return (NULL);
	tmp->data = data;
	tmp->link = NULL;
	return (tmp);
}

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

	printf("%d\n", node->data);
	while (tmp) {
		printf("%d\n", tmp->node->data);
		tmp = tmp->next;;
	}
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

node_t	*list_to_graph(t_list *list)
{
	node_t	*node = NULL;
        t_list	*tmp = list;

	node = create_node(42);
	while (tmp) {
		connect_nodes(node, create_node(tmp->nb));
		tmp = tmp->next;
	}
        return (node);
}

link_t	*build_my_graph(void)
{
	node_t	*node = NULL;

	node = create_node(42);
	connect_nodes(node, create_node(48));
	connect_nodes(node, create_node(60012));
	connect_nodes(node->link->node, create_node(30012));
	printf("node %d\n", node->link->node->link->node->data);
	return (node->link);
}

void	get_tab(char **tab)
{
	char	*s = NULL;
	int	i = 0;

	while ((s = get_next_line(0))) {
		tab[i] = s;
		i += 1;
	}
	tab[i] = NULL;
	free(s);
}

int	main(UNU int ac, UNU char **av)
{
	first_end	*list;
	node_t	*node = NULL;
	link_t	*link;
	char	**tab = NULL;

	if((list = malloc(sizeof(first_end))) == NULL)
		return (84);
	init(list);
	if ((tab = malloc(sizeof(char *) * 4096)) == NULL)
		return (0);
	get_tab(tab);
	my_checker(list, tab);
	while (list->first) {
		my_printf("lol %s\n", list->first->links_room);
		list->first = list->first->next;
	}
	//node = list_to_graph(list);
	//link = build_my_graph();
	return (0);
}
