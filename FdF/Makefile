NAME = FdF
CFLAGS = -Wall -Wextra -Werror
MK_MLX = mlx_linux
MAIN = main.c
CC = gcc

CFILES = read_map.c \
	bresenham.c \
	isometry.c \
	fdf_utils.c

MK_PRINTF = ./ft_printf/libftprintf.a

OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MK_PRINTF):
	cd ft_printf/ && make && cd ..


$(NAME): $(MK_PRINTF) $(OFILES) $(MAIN)
	make -C $(MK_MLX)
	$(CC) $(OFILES) $(MAIN) -Lft_printf -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C $(MK_MLX)
	rm -f $(OFILES)
	cd ft_printf/ && make clean && cd ..
	cd libft/ && make clean
	
fclean: clean
	rm -f $(NAME)
	make clean -C $(MK_LMX)
	cd ft_printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..

re: fclean all
