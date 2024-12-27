NAME = philo
CC = gcc -g
LIBFT_N = libft.a
CFLAGS  = -Wall -Wextra -Werror -O3 -pthread
CFILES =	error.c	moni.c philo_utils.c set_up.c main.c philo_utils2.c mutex.c routine.c
LIBFT_D = ./libft
HEADER = philo.h
OFILES = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(CFILES) $(HEADER)
		@ make -C $(LIBFT_D)
		@ test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
		@ $(CC) $(CFLAGS) $(CFILES) -L $(LIBFT_D) -l ft -o $(NAME)
		@ echo "Make <OK!>"

clean:
		@ make clean -C $(LIBFT_D)
		@ rm -f $(OFILES)
		@ echo "Make clean <OK!>"

fclean: clean
		@ make fclean -C $(LIBFT_D)
		@ rm -f $(NAME)
		@ echo "Make clean <OK!>"

re: fclean all

.PHONY: all clean fclean re
