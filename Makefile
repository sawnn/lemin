##
## EPITECH PROJECT, 2017
## makefile
## File description:
## gaspacho andalou
##

SRC	=	./src/main.c			\
		./src/fill_struct_info.c	\
		./src/linked_list.c		\
		./src/utility_two.c		\
		./src/utility.c			\
		./src/get_next_line.c		\
		./src/graph_utils.c		\
		./src/print_tab.c		\
		./src/base.c			\
		./src/checkpoint.c		\
		./src/errors.c			\
		./src/errors_two.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-W -Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) ./libprintf.a

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
