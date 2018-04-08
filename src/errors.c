/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** gestion d'erreur par le grand Dali
*/

#include "my.h"

char	*check_nb(char *tab)
{
	int	i = 0;

	while (tab[++i])
		if (tab[i] < 48 || tab[i] > 57)
			return (NULL);
	return (tab);
}

char	*check_line_two(char *tab, int a)
{
	char	*str = tab;
	static	int	b = 0;

	while (tab[a]) {
		if (check_nb(tab) != NULL) {
			b += 1;
			b > 1 ? str = NULL : 0;
			return (str);
		}
		else if (tab[a] == '-' && tab[a + 1] != 0 && a != 0)
			break;
		else if (tab[a + 1] == 0 && tab[a] != '-')
			return (NULL);
		else
			a += 1;
	}
	return (tab);
}

char	*check_line(char **tab)
{
	int	i = -1;
	int	a = 0;
	int	b = 0;
	int	c = 0;

	while (tab[++i]) {
		while (tab[i + 1] && my_strncmp(tab[i], "#", 1) == 0)
			tab[i + 1] ? i += 1 : (c = 1);
		if (!tab[i] || c == 1 || my_strncmp(tab[i + 1], "#", 1) == 0)
			break;
		if (count_space(tab[i]) == 2 || count_space(tab[i]) > 3)
			return (NULL);
		else if (count_space(tab[i]) == 1)
			check_line_two(tab[i], a) == NULL ? b = 1 : 0;
		if (b == 1)
			return (NULL);
		a = 0;
	}
	return (tab[0]);
}
