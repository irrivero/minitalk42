SRCS = client.c server.c

OBJS := $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

${NAME}: server client

server: server.o
	@make -C libft
	@make -C printf
	${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lfprintf -o server

client: client.o
	@make -C libft
	@make -C printf
	${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lfprintf -o client

libft:
	make -C libft

printf:
	make -C printf

clean:
	make clean -C libft
	make clean -C printf
	${RM} ${OBJS}

fclean: clean
	${RM} server client

re: fclean all

.PHONY: libft printf