/*
** EPITECH PROJECT, 2018
** utility
** File description:
** gaspacho andalou
*/

#include "my.h"

int	my_strlen(char *str)
{
	int	i = -1;

	while (str[++i] != '\0');
	return (i);
}

char	*my_strcat(char *s1, char *s2)
{
	int	i = -1;
	int	j = -1;
	int	k = my_strlen(s1) + my_strlen(s2) + 2;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * k)) == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		tmp[i] = s1[i];
	while (s2[++j] != '\0') {
		tmp[i] = s2[j];
		i += 1;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*my_strdup(char *str)
{
	int	i = -1;
	char	*tmp = NULL;

	if ((tmp = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[++i] != '\0')
		tmp[i] = str[i];
	tmp[i] = '\0';
	return (tmp);
}
