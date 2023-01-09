SERVER = server.c helpers.c

CLIENT = client.c helpers.c checker.c

SERVER_OBJ = $(SERVER:.c=.o)

CLIENT_OBJ = $(CLIENT:.c=.o)

OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

COMP = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server

CLIENT_NAME = client

NAME = server_client

all: $(NAME)

$(NAME): server client

server:
	$(COMP) $(CFLAGS) $(SERVER) -o $(SERVER_NAME)

client:
	$(COMP) $(CFLAGS) $(CLIENT) -o $(CLIENT_NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all
