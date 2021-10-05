SERVER			= server
CLIENT			= client
NAME		= $(SERVER) $(CLIENT)

LIBFT		= ./libft

CFLAGS		= -Wall -Wextra -Werror -I

RM			= rm -rf

SERVER_SRC		= ./mandatory/server.c \
				  ./utils.c
CLIENT_SRC		= ./mandatory/client.c \
				  ./utils.c

SERVER_O	= $(SERVER_SRC:%.c=%.o)
CLIENT_O	= $(CLIENT_SRC:%.c=%.o)
OBJS 		= $(SERVER_O) $(CLIENT_O)  

HEADER 		= ./inc

NAME: $(SERVER) $(CLIENT)
all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(HEADER) -o $@ -c $^

$(SERVER):	$(SERVER_O)
			$(MAKE) bonus -C $(LIBFT)
			gcc $(SERVER_O) ./libft/libft.a -o $(SERVER)

$(CLIENT): 	$(CLIENT_O)
			$(MAKE) bonus -C $(LIBFT)
			gcc $(CLIENT_O) ./libft/libft.a -o $(CLIENT)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(SERVER) $(CLIENT)
re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re
