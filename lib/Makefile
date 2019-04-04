##
## EPITECH PROJECT, 2019
## Custom Lib C
## File description:
## Makefile to compile the lib
##


NAME			=	libmy.a

SRC_LIST		=	list/list_create.c 	 	\
					list/list_delete.c 	  	\
					list/list_destroy.c   	\
					list/list_each.c      	\
					list/list_get_by_id.c 	\
					list/list_length.c  	\
					list/list_push.c    	\

SRC_NUMBER		=	number/my_is_nbr.c

DIR				=	./src/

SRCS			=	$(addprefix $(DIR), $(SRC_LIST))	\
					$(addprefix $(DIR), $(SRC_NUMBER))

OBJ				=	$(SRCS:.c=.o)

CFLAGS			=	-pedantic -W -Wall -Wextra -I./include/ -c

CC				=	gcc

all: $(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) $(SRCS)
			ar -rc $(NAME) *.o

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

re:			fclean all

tests_run:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -lcriterion --coverage -o test
			./test

clean:
			rm -f *.o $(OBJ) *~ \#*\# \

fclean:		clean
			rm -f $(NAME)

.PHONY:		all valgrind wc debug re tests_run clean fclean $(NAME)