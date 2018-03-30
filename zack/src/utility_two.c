/*
1;4804;0c1;4804;0c** EPITECH PROJECT, 2018
** utility_two.c
** File description:
** utility_two
*/

#include "../include/my.h"

int	my_strncmp(char	*str1, char *str2, int nb)
{
	int	i = 0;

	while (str1[i] && str2[i] && i < nb && str1[i] == str2[i])
		i += 1;
	if (i == nb)
		return (0);
	return (1);
}

int	count_space(char *str)
{
	int	i = 0;
	int	space = 1;

	while (str[i]) {
		if (str[i] == ' ')
			space += 1;
		i += 1;
	}
	return (space);
}

char	*malloc_for_word(int i, char *arg, char *str, char c)
{
	int	a = 0;

	while (str[i] != 0) {
		if (str[i] == c) {
			arg = malloc(sizeof(char) * a + 1);
			return (arg);
		}
		i += 1;
		a += 1;
	}
	arg = malloc(sizeof(char) * a + 1);
	return (arg);
}

char	*word_nbr_nb(char *str, int nb)
{
	int	space = 1;
	int	i = -1;
	int	a = 0;
	char	*word = NULL;

	while (str[++i] && space < nb) {
		if (str[i]  == ' ')
			space += 1;
	}
	word = malloc_for_word(i, word, str, ' ');
	while (str[i]) {
		if (str[i] == ' ') {
			word[a] = 0;
			return (word);
		}
		word[a] = str[i];
		a += 1;
		i += 1;
	}
	word[a] = 0;
	return (word);
}

int	my_strcmp(char *str1, char *str2)
{
	int	i = -1;

	if (!str1 || !str2 || (my_strlen(str1) != my_strlen(str2)))
		return (0);
	while (str1[++i] != '\0')
		if (str1[i] != str2[i])
			return (0);
        return (1);
}
