##
## EPITECH PROJECT, 2017
## makefile
## File description:
## gaspacho andalou
##

SRC	=	./src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lemin

CFLAGS	=	-W -Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib_printf
	gcc -o $(NAME) $(OBJ) ./lib_printf/libmy.a

clean:
	rm -f ./src/*.o
	rm -f *~
	rm -f *~
	rm -f ./lib_printf/include/*~
	rm -f ./lib_printf/src/*.o
	rm -f ./lib_printf/src/*~
	rm -f vg*
	rm -f ./src/*~
	rm -f ./include/*~

fclean: clean
	rm -f $(NAME)
	rm -f ./lib_printf/libmy.a

re: fclean all
