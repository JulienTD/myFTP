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

SRCS_CRITERION		=	./tests/test.c

DIR				=	./src/

SRCS			=	$(addprefix $(DIR), $(SRC_FTP_SERVER))	\
					$(addprefix $(DIR), $(SRC_FTP_CLIENT))	\
					$(addprefix $(DIR), $(SRC_QUEUE))		\
					$(addprefix $(DIR), $(SRC_COMMAND))

SRC_MAIN		=	$(addprefix $(DIR), $(SRC))

OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

OBJ				=	$(SRCS:.c=.o)

CFLAGS			=	-pedantic -W -Wall -Wextra -I./include/ -I./lib/include/

CC				=	gcc

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			make -C ./lib/ re
			$(CC) $(CFLAGS) $(OBJ) -L./lib/ -lmy -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

re:			fclean all

tests_run:	$(SRC_MAIN) $(SRCS)
			make -C ./lib/ re
			$(CC) $(CFLAGS) $(SRCS) $(SRCS_CRITERION) -lcriterion -L./lib/ -lmy --coverage -o test
			./test

clean:
			rm -f $(OBJ) *~ \#*\# *.gcno *.gcda

fclean:		clean
			rm -f $(NAME)

.PHONY:		all valgrind wc debug re tests_run clean fclean $(NAME)