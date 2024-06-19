NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = client.c server.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c

# MK_PRINTF:
# 	cd ft_printf/ && make && cd ..

$(NAME): client server

server: server.c 
	cd ft_printf/ && make && cd ..
	$(CC) $(CFLAGS) server.c -L./ft_printf -lftprintf -o server
	
client: client.c 
	cd ft_printf/ && make && cd ..
	$(CC) $(CFLAGS) client.c -L./ft_printf -lftprintf -o client
	
clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -f $(OFILES)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
	
	
