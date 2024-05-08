NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_int.c \
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_print_p.c

MK_LIBFT = ../libft/libft.a

OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MK_LIBFT):
	cd ../libft/ && make && cd ../ft_printf

$(NAME): $(MK_LIBFT) $(OFILES)
	cp $(MK_LIBFT) $(NAME)
	ar -rc $(NAME) $(OFILES)


clean: 
	rm -f $(OFILES)
	cd ../libft/ && make clean

fclean: clean
	rm -f $(NAME)
	cd ../libft/ && make fclean

re: fclean all

.PHONY: all clean fclean re
