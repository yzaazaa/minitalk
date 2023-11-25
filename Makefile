CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

CLIENT_SRC = client.c helpers.c
SERVER_SRC = server.c helpers.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
OBJS = $(CLIENT_OBJ) $(SERVER_OBJ)

CLIENT = client
SERVER = server
NAME = server_client

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all