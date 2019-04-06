##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##


NAME			=	myftp

SRC				=	main.c

SRC_COMMAND			=	command/command_create.c \
						command/command_destroy.c \
						command/command_dispatch.c \
						command/command_init.c

SRC_COMMAND_EXECUTOR=	command/executor/user_command_executor.c \
						command/executor/pass_command_executor.c

SRC_FTP_SERVER		=	ftp/server/server_create.c \
						ftp/server/server_listen.c \
						ftp/server/server_start.c  \
						ftp/server/server_broadcast.c \
						ftp/server/server_send.c \
						ftp/server/server_receive.c \
						ftp/server/server_execute_queue.c \
						ftp/server/server_configure.c

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
					$(addprefix $(DIR), $(SRC_COMMAND))		\
					$(addprefix $(DIR), $(SRC_COMMAND_EXECUTOR))

SRC_MAIN		=	$(addprefix $(DIR), $(SRC))

OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

OBJ				=	$(SRCS:.c=.o)

CFLAGS			=	-fsanitize=address -W -Wall -Wextra -I./include/ -I./lib/include/ -g3

CC				=	gcc

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			make -C ./lib/ re
			$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) -L./lib/ -lmy -lasan -o $(NAME)

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