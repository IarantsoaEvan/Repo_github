NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 1st_set_up.c \
	check_error_utils.c \
	ft_split_utils.c \
	print_error.c
	
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) push_swap.h
	ar rc $(NAME) $(OFILES)
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OFILES)
fclean: clean
		rm -f $(NAME)
re: fclean all
