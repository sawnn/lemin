/*
** EPITECH PROJECT, 2018
** get_next line
** File description:
** gaspacho andalou
*/

#include "my.h"

char	*get_next_line(int fd)
{
	char	buff[READ_SIZE];
	int	i = 0;
	int	j = 0;
	char	*ret;

	if ((ret = malloc(sizeof(char) * 1)) == NULL || fd == -1)
		return (NULL);
	ret[i] = '\0';
	buff[i] = '\0';
	while (13) {
		if ((read(fd, buff, READ_SIZE)) == 0)
			return (ret[0] != '\0' ? ret : NULL);
		else if (buff[i] != '\0' && buff[i] != '\n') {
			ret = my_strcat(ret, buff);
			j = j + 1;
		} else
			return (ret && (ret[j] = 0) ? ret : ret);
	}
}
