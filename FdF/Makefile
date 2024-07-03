NAME = FdF
CFLAGS = -Wall -Wextra -Werror
MK_MLX = mlx_linux
MAIN = main.c
CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MK_PRINTF):
	cd ft_printf/ && make && cd ..


$(NAME): $(MK_PRINTF) $(MAIN)
	make -C $(MK_MLX)
	$(CC) $(MAIN) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C $(MK_MLX)
	rm -f $(OFILES)
	
fclean: clean
	make clean -C $(MK_LMX)
	rm -f $(NAME)

re: fclean all
