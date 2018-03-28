/*
** EPITECH PROJECT, 2018
** linked_list.c
** File description:
** function for link list
*/

#include "../include/my.h"

void	init(first_end	*lc)
{
	lc->first = NULL;
	lc->last = NULL;
}

void	put_in_list(first_end *lc, char *str, int i, int ant)
{
	info_room	*room = malloc(sizeof(info_room));

	if (!room)
		exit(EXIT_FAILURE);
	room->room_name = word_nbr_nb(str, 1);
	room->pos_x = my_getnbr(word_nbr_nb(str, 2));
	room->pos_y = my_getnbr(word_nbr_nb(str, 3));
	room->start = '0';
	room->end = '0';
	i == 1 ? room->start = '1' : 0;
	i == 2 ? room->end = '1' : 0;
	room->ant = 0;
	room->start = '1' ? room->ant = ant : 0;
	room->prev = lc->last;
	room->next = NULL;
	if (lc->last)
		lc->last->next = room;
	else
		lc->first = room;
	lc->last = room;
}

void	print_list(first_end lc)
{
	info_room	*room = lc.first;

	while (room) {
		my_printf("name = %s\n", room->room_name);
		my_printf("link_room = %s\n", room->links_room);
		my_printf("x = %d\n", room->pos_x);
		my_printf("y = %d\n", room->pos_y);
		my_printf("ant = %d\n", room->ant);
		my_printf("start = %c\n", room->start);
		my_printf("end = %c\n", room->end);
		room = room->next;
		my_printf("\n\n");
	}
}

void	put_links_room(first_end *lc, char *str)
{
	info_room	*rooms = lc->first;
	char	*room = get_room(str);
	char	*link = get_link(str);

	while (my_strncmp(room, rooms->room_name, my_strlen(rooms->room_name)) == 1)
		rooms = rooms->next;
	if (!rooms->links_room)
		rooms->links_room = link;
	else {
		rooms->links_room = my_strcat(rooms->links_room, " ");
		rooms->links_room = my_strcat(rooms->links_room, link);
	}
}
