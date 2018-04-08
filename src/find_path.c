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

	if (!tmp)
		return (NULL);
	while (i >= 0 && str[i] != 0 && str[--i] && str[i] != ' ');
	while (i >= 0 && str[i] != 0 && str[--i] && str[i] != ' ');
	while (i >= 0 && str[i] != 0 && str[++i] && str[i] != ' ')
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
	int	i = -1;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * my_strlen(str) + 5)) == NULL)
		return (NULL);
	while (++i != n)
		tmp[i] = str[i];
	tmp[i] = '\0';
	return (tmp);
}
