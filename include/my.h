/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define READ_SIZE 1
#ifndef MY_H_
#define MY_H_

typedef	int	(*ptab_t)(char **); /*prototype tableau de pointeurs sur fonction*/
/* structure qui comporte les infos des chambres */
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
}	first_end_t;

typedef	first_end_t first_end;
typedef info_room_t info_room;

/*PRINTF & GNL*/
int	my_printf(char *, ...);
char	*get_next_line(int);

/*MAIN.C*/
int	main(void);

/*BASE.C*/
int	my_reader(first_end *); /* lit le ficher, lance le parcing, convertit en tab et envoie le programme a emiloche*/
char	**str_to_wordtab(char *str); /* convertit une str en tab*/
char	*remplitab(char *dest, char *src, int j); /* rempli les lignes du tableau */

/* CHECKPOINT.C*/
int	my_checkpoint(first_end *, char **);
int	my_ptab(int, char **);

/*ERRORS.C*/
int	checknumant(char **);
int	check_starter(char **);
int	check_ender(char **);
int	check_nonb(char **);
int	check_gline(char **);

/*ERRORS_TWO.C*/
int	check_line(char *);
int	check_twocommand(char **);
int	str_compar(char *, char *);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_eolen(char *); /*sert à compter le nombre de mots (grace aux '\n')*/
int	my_getnbr(char *);

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

/* FILL_STRUCT_INFO */
char	*get_link(char *);
char	*get_room(char *);
int	my_checker(first_end *, char **);

#endif	/*!_MY_H_*/
