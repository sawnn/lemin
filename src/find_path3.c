/*
** EPITECH PROJECT, 2018
** find path3
** File description:
** gaspacho andalou
*/

#include "my.h"
char	**moves(char **tmp, int **ant, int nbr_ant, int nbr)
{
	int i = -1;
	int j = -1;

	while (ant[0][nbr_ant - 1] != -1 || check_nbr_ant(ant, nbr) != 0) {
		while (++i < nbr);
		i--;
		while (--i >= 0)
			moves_2(i, ant, tmp, nbr, nbr_ant, &j);
		write(1, "\n", 1);
	}
	return (tmp);
}

char	**get_moves(char *str, int ant)
{
	char **tmp = malloc(sizeof(char *) * my_strlen(str));
	int i = -1;
	int j = -1;
	int **is_ant = malloc(sizeof(int*) * my_strlen(str));
	while (str[++i]) {
		tmp[++j] = my_strndup(&str[i], my_strlen_char(&str[i], ' '));
		i = i + my_strlen_char(&str[i], ' ');
	}
	tmp[++j] = NULL;
	is_ant[0] = malloc(sizeof(int) * ant + 4);
	j = 0;
	i = -1;
	while (++i < ant)
		is_ant[0][i] = i + 1;
	is_ant[0][i] = -1;
	while (tmp[++j]) {
		is_ant[j] = malloc(sizeof(int));
		is_ant[j][0] = 0;
	}
	return (moves(tmp, is_ant, ant, j));
}

char	*delete_name(char *str)
{
	int i = my_strlen(str);

	while (i >= 0 && str[--i] != ' ');
	if (str[i] != ' ')
		return (NULL);
	str[i] = 0;
	return (str);
}

char	**find_path(node_t *start, node_t **all_node)
{
	node_t *tmp = start;
	char *str = my_strdup(tmp->name);

	while (tmp->link->node && tmp->end == 0) {
		tmp->bool = 1;
		while (tmp->link->next != NULL && tmp->link->node->bool == 1)
			tmp->link = tmp->link->next;		
		if ((tmp->link->next == NULL && tmp->link->node->bool == 1)) {
			tmp = find_maillon(all_node, str);
			str = delete_name(str);
		} else {
			tmp = tmp->link->node;
			str = my_strcat(str, my_strcat(" ", tmp->name));
		}
		if (str == NULL)
			return (NULL);
	}
	write(1, "#moves\n", 7);
	return (get_moves(str, start->ant));
}
