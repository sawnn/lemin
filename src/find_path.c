/*
** EPITECH PROJECT, 2018
** find_path.c
** File description:
** a
*/

#include "my.h"

char	*find_name(char *str)
{
	int i = my_strlen(str);
	int j = -1;
	char *tmp = malloc(sizeof(char) * i);

	while (str[--i] && str[i] != ' ');
	while (str[--i] && str[i] != ' ');
	while (str[++i] && str[i] != ' ')
		tmp[++j] = str[i];
	tmp[++j] = 0;
	return (tmp);
}

node_t	*find_maillon(node_t **all_node, char *str)
{
	char *tmp = find_name(str);
	int	i = -1;

	while (all_node[++i]) {
		if (my_strcmp(all_node[i]->name, tmp) == 1)
			return (all_node[i]);
	}
	return (all_node[i - 1]);
}

int	my_strlen_char(char *str, char c)
{
	int i = -1;

	while (str[++i] && str[i] != c);
	return (i);
}

char    *my_strndup(char *str, int n)
{
        int     i = -1;
        char    *tmp = NULL;

        if ((tmp = malloc(sizeof(char) * my_strlen(str) + 5)) == NULL)
                return (NULL);
        while (++i != n)
                tmp[i] = str[i];
        tmp[i] = '\0';
        return (tmp);
}

int	check_nbr_ant(int **ant, int nbr)
{
	int i = 0;

	while (++i < nbr)
		if (ant[i][0] != 0)
			return (1);
	return (0);
}

void	write_moves(int nbr, char *str)
{
	write(1, "P", 1);
	my_put_nbr(nbr);
	write(1, "-", 1);
	write(1, str, my_strlen(str));
}

int	check_first(int *ant, int nbr)
{
	int i = -1;

	while (++i < nbr)
		if (ant[i] != -1)
			return (1);
	return (0);
}

void	check_space(int **ant, int i, int nbr_ant)
{
	if (i > 1 && ant[i - 1][0] != 0)
		write(1, " ", 1);
	if (i == 1 && check_first(ant[0], nbr_ant) == 1)
		write(1, " ", 1);
}

void	moves(char **tmp, int **ant, int nbr_ant, int nbr)
{
	int i = -1;
	int j = -1;

	while (ant[0][nbr_ant - 1] != -1 || check_nbr_ant(ant, nbr) != 0) {
		while (++i < nbr);
		i--;
		while (--i >= 0) {			
			if (i != 0 && ant[i][0] != 0 && ant[i + 1][0] == 0) {
				ant[i + 1][0] = ant[i][0];
				ant[i][0] = 0;
				write_moves(ant[i + 1][0], tmp[i + 1]);
				check_space(ant, i, nbr_ant);
			}
			if (i == 0 && ant[i + 1][0] == 0 && ant[0][nbr_ant - 1] != -1) {
				ant[i + 1][0] = ant[i][++j];
				ant[i][j] = -1;
				write_moves(ant[i + 1][0], tmp[i + 1]);
				check_space(ant, i, nbr_ant);
			}			
			if (i == nbr - 2 && ant[i + 1][0] != 0)
				ant[i + 1][0] = 0;
		}
		write(1, "\n", 1);
	}
}

void	get_moves(char *str, int ant)
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
	moves(tmp, is_ant, ant, j);
}

char	*delete_name(char *str)
{
	int i = my_strlen(str);

	while (str[--i] != ' ');
	str[i] = 0;
	return (str);
}

char	**find_path(node_t *start, node_t **all_node)
{
	node_t *tmp = start;
	char *str = my_strdup(tmp->name);

	while (tmp->link->node && tmp->end == 0) {
		tmp->bool = 1;
		while (tmp->link->next != NULL && tmp->link->node->bool == 1) {
			tmp->link = tmp->link->next;
		}
		if (tmp->link->next == NULL && tmp->link->node->bool == 1) {
			tmp = find_maillon(all_node, str);
			str = delete_name(str);
		} else {
			tmp = tmp->link->node;			
			str = my_strcat(str, my_strcat(" ", tmp->name));
		}
	}
        write(1, "#moves\n", 7);
	get_moves(str, start->ant);
	return (NULL);
}
