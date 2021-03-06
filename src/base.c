/*
** EPITECH PROJECT, 2018
** base.c
** File description:
** base du programme
*/

#include "my.h"

char	**my_reader(char **tab)
{
	char	*str = NULL;
	char	*dest = NULL;
	char	*tmp = NULL;
	int	returne = 0;

	if ((str = get_next_line(0)) == NULL)
		return (NULL);
	while (str) {
		if ((tmp = get_next_line(0)) != NULL)
			(str = my_strcat(str, "\n")) == NULL ? returne = 84 : 0;
		(dest = my_strcat(dest, str)) == NULL ? returne = 84 : 0;
		str = tmp;
	}
	(tab = my_str_to_word_tab(dest, '\n')) == NULL ? returne = 84 : 0;
	if (my_checkpoint(tab) == NULL || returne == 84) {
		print_tab(tab);
		return (NULL);
	}
	return (tab);
}

char	**my_malloc_line(char **my_tab, char *str, char c)
{
	int	i = -1;
	int	nb = 0;
	int	a = 0;
	int	b = 0;
	while (str[++i]) {
		if (str[i] == c) {
			my_tab[nb] = malloc(sizeof(char) * a + 2);
			!my_tab[nb] ? b = 1 : 0;
			my_tab[nb][a] = 0;
			a = 0;
			nb += 1;
		}
		if (b == 1)
			return (NULL);
		a += 1;
	}
	if ((my_tab[nb] = malloc(sizeof(char) * a + 2)) == NULL)
		return (NULL);
	my_tab[nb][a] = 0;
	return (my_tab);
}

char	**my_malloc_tab(char **my_tab, char *str, char c)
{
	int	i = 0;
	int	nb = 0;

	while (str[i]) {
		if (str[i] == c)
			nb += 1;
		i += 1;
	}
	if ((my_tab = malloc(sizeof(char *) * (nb + 2))) == NULL)
		return (NULL);
	else if ((my_tab = my_malloc_line(my_tab, str, c)) == NULL)
		return (NULL);
	my_tab[nb + 1] = NULL;
	return (my_tab);
}

char	**my_str_to_word_tab(char *str, char c)
{
	char	**my_tab = NULL;
	int	i = -1;
	int	a = 0;
	int	t = 0;

	my_tab = my_malloc_tab(my_tab, str, c);
	while (str[++i]) {
		if (str[i] == c) {
			my_tab[t][a] = 0;
			i += 1;
			t += 1;
			a = 0;
		}
		my_tab[t][a] = str[i];
		a += 1;
	}
	my_tab[t][a] = 0;
	my_tab[t + 1] = NULL;
	return (my_tab);
}
