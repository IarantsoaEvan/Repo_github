NAME = push_swap
MAIN = ./main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = 1st_set_up.c \
	check_error_utils.c \
	print_error.c

MK_PRINTF = ./ft_printf/libftprintf.a
	
OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MK_PRINTF):
	cd ft_printf/ && make && cd ..

$(NAME):  $(MK_PRINTF) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) $(MAIN) -L./ft_printf -lftprintf -o $(NAME) 

clean:
	rm -f $(OFILES) && rm -f $(MAIN:.c=.o)
	cd ft_printf/ && make clean && cd ..
	cd libft/ && make clean
fclean: clean
	rm -f $(NAME)
	cd ft_printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re
