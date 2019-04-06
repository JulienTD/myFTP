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

SRC_HASHMAP		=	hashmap/hashmap_create.c 	 	\
					hashmap/hashmap_delete.c 	  	\
					hashmap/hashmap_destroy.c   	\
					hashmap/hashmap_each.c      	\
					hashmap/hashmap_get_by_id.c 	\
					hashmap/hashmap_length.c  	\
					hashmap/hashmap_push.c    	\
					hashmap/hashmap_get_value.c

SRC_NUMBER		=	number/my_is_nbr.c

SRC_STRING		=	string/my_str_split.c \
					string/my_strcpy.c

DIR				=	./src/

SRCS			=	$(addprefix $(DIR), $(SRC_LIST))	\
					$(addprefix $(DIR), $(SRC_NUMBER))	\
					$(addprefix $(DIR), $(SRC_STRING))	\
					$(addprefix $(DIR), $(SRC_HASHMAP))

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