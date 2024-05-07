NAME = push_swap
MAIN = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 1st_set_up.c \
	check_error_utils.c \
	ft_split_utils.c \
	print_error.c
	
OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) push_swap.h
	$(CC) $(CFLAGS) $(OFILES) $(MAIN) -o $(NAME) 

clean:
	rm -f $(OFILES)
fclean: clean
		rm -f $(NAME)
re: fclean all
