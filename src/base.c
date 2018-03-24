/*
** EPITECH PROJECT, 2018
** base.c
** File description:
** base du programme
*/

#include "my.h"

int	my_reader(void)
{
	char	*str;
	char	*dest = "";
	char	**tab;
	int	returner = 0;

	while ((str = get_next_line(0)) != NULL) {
		(str = my_strcat(str, "\n")) == NULL ? returner = 84 : 0;
		(dest = my_strcat(dest, str)) == NULL ? returner = 84 : 0;
		free(str);
	}
	(tab = str_to_wordtab(dest)) == NULL ? returner = 84 : 0;
	if (returner == 84)
		return (84);
	return (my_checker(tab));//emilie(tab));
}

char	**str_to_wordtab(char *str)
{
	char	**tab;
	int	idx_tab = 0;
	int	i = 0;
	int	len = 0;
	int	j = 0;

	if ((tab = malloc(sizeof(char *) * my_eolen(str) + sizeof(char *))) == NULL)
		return (NULL);
	for (idx_tab = 0; idx_tab < my_eolen(str) + 1; idx_tab += 1) {		
		for (; str[i] != '\n' && str[i]; i += 1, len += 1);
		if ((tab[idx_tab] = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		remplitab(tab[idx_tab], str, j);
		for (; str[j] != '\n' && str[j]; j += 1);
		len = 0;
		i += 1;
		j += 1;
	}
	return (tab);
}

char	*remplitab(char *dest, char *src, int j)
{
	int	idx = 0;

	for (idx = 0; src[j] != 10 && src[j]; idx += 1, j += 1)
		dest[idx] = src[j];
	dest[idx] = 0;
	return (dest);
}

int	my_checker(char **tab)
{
	int	i = 0;
	return (check_numant(tab[1]));
}
int	check_numant(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1) {
		return (0);
	}
}
