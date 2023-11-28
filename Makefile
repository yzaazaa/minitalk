# HEADER FILES
HEADER = minitalk.h

# SOURCE FILES
SERVER_SRCS = server.c error.c

CLIENT_SRCS = client.c ft_atoi.c error.c

SERVER_BONUS_SRCS = server_bonus.c error.c

CLIENT_BONUS_SRCS = client_bonus.c ft_atoi.c error.c

SRCS = $(SERVER_SRCS) $(CLIENT_SRCS)

PRINTF = ft_printf/libftprintf.a

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

NAME = $(CLIENT) $(SERVER)

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
	@echo "Making libftprintf ..."
	@make -C ft_printf/
	$(COMP) $(CFLAGS) $(SERVER_OBJS) $(PRINTF) -o $(SERVER)
	$(COMP) $(CFLAGS) $(CLIENT_OBJS) $(PRINTF) -o $(CLIENT)

bonus : $(BONUS_OBJS)
	@echo "Making libftprintf ..."
	@make -C ft_printf/
	$(COMP) $(CFLAGS) $(SERVER_BONUS_OBJS) $(PRINTF) -o $(SERVER)
	$(COMP) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(PRINTF) -o $(CLIENT)

clean : 
	@make clean -C ft_printf
	@echo "Deleting $(OBJS)"
	@echo "Deleting $(BONUS_OBJS)"
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	@make fclean -C ft_printf
	@rm -f  $(OBJS) $(BONUS_OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean