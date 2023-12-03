# HEADER FILES
HEADER = minitalk.h

# SOURCE FILES
SERVER_SRCS = server.c error.c ft_put.c

CLIENT_SRCS = client.c ft_atoi.c error.c ft_put.c

SERVER_BONUS_SRCS = server_bonus.c error.c ft_put.c

CLIENT_BONUS_SRCS = client_bonus.c ft_atoi.c error.c ft_put.c

SRCS = $(SERVER_SRCS) $(CLIENT_SRCS)

# OBJECT FILES
SERVER_OBJS = ${SERVER_SRCS:.c=.o}

CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}

SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}

CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}

OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)

BONUS_OBJS = $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

# EXECUTABLES
CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

NAME = $(CLIENT) $(SERVER)

NAME_BONUS = $(CLIENT_BONUS) $(SERVER_BONUS)

# COMPILER
COMP = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror

# RULES
all : $(NAME)

%.o : %.c $(HEADER)
	@echo "Compiling $< ..."
	@$(COMP) $(CFLAGS) -c $< 

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)
	$(COMP) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

bonus : $(BONUS_OBJS)
	$(COMP) $(CFLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS)
	$(COMP) $(CFLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS)

clean : 
	@echo "Deleting object files"
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	@echo "Deleting all"
	@rm -f  $(OBJS) $(BONUS_OBJS) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : fclean clean