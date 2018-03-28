/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef MY_H_
#define MY_H_
#define UNU __attribute__((unused))

typedef	struct	info_room_s {
	char	*room_name;
	char	*links_room;
	int	pos_x;
	int	pos_y;
	int	ant;
	char	start;
	char	end;
	struct	info_room_s	*prev;
	struct	info_room_s	*next;
}	info_room_t;

/* debut et fin de la structure */
typedef	struct	first_end_s {
	struct	info_room_s	*first;
	struct	info_room_s	*last;
} first_end_t;

typedef	first_end_t first_end;
typedef info_room_t info_room;

typedef struct node {
	int		data;
	struct link	*link;
} node_t;

typedef struct link {
	node_t		*node;
	struct link	*next;
} link_t;

typedef struct s_list {
	int		nb;
	struct s_list	*next;
} t_list;
#define READ_SIZE 1
int	my_printf(char *, ...);
char	*get_next_line(int);

/* FILL_STRUCT_INFO */
char	*get_link(char *);
char	*get_room(char *);
int	my_checker(first_end *, char **);

/*LINKED_LIST */
void	init(first_end *);
void	put_in_list(first_end *, char *, int, int); /* met un maillon dans la liste et l'initialise */
void	print_list(first_end lc);
void	put_links_room(first_end *, char *);

/* UTILITY_TWO */
int	my_strncmp(char *, char *, int);
int	count_space(char *);
char	*malloc_for_word(int, char *, char *, char); /* malloc pour un mot dans une pharse */
char	*word_nbr_nb(char *, int); /* return the nb word in a char* */
int	strcompar(char *, char *);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_eolen(char *); /*sert à compter le nombre de mots (grace aux '\n')*/
int	my_getnbr(char *);

#endif
