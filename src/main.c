/*
** EPITECH PROJECT, 2018
** lol
** File description:
** gaspacho andalou
*/

#include "my.h"

int	main(void)
{
	first_end	*first = NULL;
	char	**tab = NULL;

	if ((tab = my_reader()) == NULL)
		return (84);
	my_checker(first, tab);
}
