##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##


NAME			=	myftp

SRC				=	main.c

SRC_COMMAND			=	command/command_create.c \
						command/command_destroy.c

SRC_FTP_SERVER		=	ftp/server/server_create.c \
						ftp/server/server_listen.c \
						ftp/server/server_start.c  \
						ftp/server/server_broadcast.c \
						ftp/server/server_send.c \
						ftp/server/server_receive.c

SRC_FTP_CLIENT		=	ftp/client/client_create.c 	\
						ftp/client/client_destroy.c \
						ftp/client/client_disconnect.c

SRC_QUEUE			=	queue/queue_add_command.c \
						queue/queue_add_existing_queue.c \
						queue/queue_retrieve_command.c

DIR				=	./src/

SRCS			=	$(addprefix $(DIR), $(SRC))				\
					$(addprefix $(DIR), $(SRC_FTP_SERVER))	\
					$(addprefix $(DIR), $(SRC_FTP_CLIENT))	\
					$(addprefix $(DIR), $(SRC_QUEUE))		\
					$(addprefix $(DIR), $(SRC_COMMAND))

OBJ				=	$(SRCS:.c=.o)

CFLAGS			=	-pedantic -W -Wall -Wextra -I./include/ -I./lib/include/

CC				=	gcc

all: $(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/ re
			$(CC) $(CFLAGS) $(OBJ) -L./lib/ -lmy -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

re:			fclean all

tests_run:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -lcriterion --coverage -o test
			./test

clean:
			rm -f $(OBJ) *~ \#*\# \

fclean:		clean
			rm -f $(NAME)

.PHONY:		all valgrind wc debug re tests_run clean fclean $(NAME)