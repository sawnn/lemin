/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define READ_SIZE 1
#ifndef MY_H_
#define MY_H_
#define UNU __attribute__((unused))
#define PARAM int nbr, int nbr_ant, int *j

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

typedef struct	room_s {
	struct	room_s *next;
	char	*name;
	char	*x;
	char	*y;
}	room_s;

typedef	first_end_t first_end;
typedef info_room_t info_room;

typedef struct node {
	char	*name;
	int	x;
	int	y;
	int	ant;
	char	start;
	char	end;
	int bool;
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

void    my_put_nbr(int);

/*FIND_PATH.C*/
char	*find_name(char *);
char    **find_path(node_t *, node_t **);
int     my_strlen_char(char *, char);
node_t	*find_maillon(node_t **, char *);
char    *my_strndup(char *, int);

/* BASE */
char	**my_reader(char **);
char	**my_str_to_word_tab(char *str, char c);
char	**my_malloc_line(char **, char *, char c);
char	**my_malloc_tab(char **, char *, char c);

/* CHECKPOINT.C */
char	**my_checkpoint(char **);
char	**check_two(char **, int, char *, char *);
char	**check_comment(char **);
int	comment(char *, int *, int *, int *);
char	*check_ant(char **);

/* ERRORS.C */
char	*check_nb(char *);
char	*check_line_two(char *, int);
char	*check_line(char **);
char	*check_room_alone(char **, room_s *);

/* ERRORS_TWO.C */
char	*check_link_same(char **);
char	*check_room_name(room_s *);
room_s	*put_list_room(room_s **, char *);
char	*check_room(char *);
char	*check_room_link(char **, room_s *, int);

/* PRINT TAB */
void	print_tab(char **);

/* FILL_STRUCT_INFO */
char	*get_link(char *);
char	*get_room(char *);
void	my_checker(first_end *, char **);

/*LINKED_LIST */
void	init(first_end *);
void	put_in_list(first_end *, char *, int *, int);
void	print_list(first_end);
void	put_links_room(first_end *, char *);

/* UTILITY_TWO */
int	my_strncmp(char *, char *, int);
int	count_space(char *);
char	*malloc_for_word(int, char *, char *, char);
char	*word_nbr_nb(char *, int);
int	my_strcmp(char *, char *);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_eolen(char *);
int	my_getnbr(char *);

/*GRAPH_UTILS.C*/
int	sp(char *, int);
int	len_tab(node_t **);
node_t	**list_to_node(first_end *);
node_t	*my_graphdup(info_room *);
int	length_list(first_end *);

/*MY_CHECKER2.C*/
int	my_check_2(char *, int *, int *);
int	my_check_3(char *, first_end *);
int	check_comment2(char *, int *, int *);
int	check_room_link2(char *, room_s *, room_s *);
char	*check_coordonne(char **, room_s *, char *, char *);

/*CONNECT.C*/
void	connect_nodes(node_t *, node_t *);
int	my_connect(char *, int, node_t **);
void	connect_rooms(node_t **, char *, int);

/*FIND_PATH2.C*/
int	check_nbr_ant(int **, int);
void	write_moves(int, char *);
int	check_first(int *, int);
void	check_space(int **, int, int);

/*FIND_PATH3.C*/
void	moves(char **, int **, int, int);
void	get_moves(char *, int);
char	*delete_name(char *);
char	**find_path(node_t *, node_t **);

/*find_path3_utils.c*/
void    moves_2(int, int **, char **, PARAM);

#endif
