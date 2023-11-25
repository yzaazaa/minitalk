CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

CLIENT_SRC = client.c helpers.c checks.c ft_puts.c
SERVER_SRC = server.c helpers.c ft_puts.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

CLIENT = client
SERVER = server
NAME = server_client

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@echo "Making the $@..."
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

$(SERVER): $(SERVER_OBJ)
	@echo "Making the $@..."
	@$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $<

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean clean