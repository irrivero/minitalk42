NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
LIB = ./helpers.c
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)

clean:
	rm -f $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

re: fclean all

.PHONY: libft printf
