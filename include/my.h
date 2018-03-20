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

/*MAIN.C*/
int	main(void);

/*BASE.C*/
int	my_read(void);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);

#endif	/*!_MY_H_*/
