# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Executables
SERVER = server
CLIENT = client

# Source files
LIBRARY_SRC = helpers.c

# Define color codes
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

# Targets
all: $(SERVER) $(CLIENT)

# Rules to build the server and client
$(SERVER): server.c $(LIBRARY_SRC)
	@echo "$(GREEN)Compiling $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)$@ is ready!$(RESET)"

$(CLIENT): client.c $(LIBRARY_SRC)
	@echo "$(GREEN)Compiling $@...$(RESET)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)$@ is ready!$(RESET)"

# Clean compiled files
clean:
	@echo "$(RED)Cleaning...$(RESET)"
	rm -f $(SERVER) $(CLIENT)
	@echo "$(RED)Cleaned!$(RESET)"

# Clean and rebuild everything
fclean: clean

# Clean, rebuild, and re-run everything
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re