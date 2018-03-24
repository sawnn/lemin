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

/*PRINTF & GNL*/
int	my_printf(char *, ...);
char	*get_next_line(int);

/*MAIN.C*/
int	main(void);

/*BASE.C*/
int	my_reader(void); /* lit le ficher, lance le parcing, convertit en tab et envoie le programme a emiloche*/
char	**str_to_wordtab(char *str); /* convertit une str en tab*/
char	*remplitab(char *dest, char *src, int j); /* rempli les lignes du tableau */

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
int	my_eolen(char *); /*sert à compter le nombre de mots (grace aux '\n')*/

#endif	/*!_MY_H_*/
