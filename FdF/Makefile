NAME = FdF
CFLAGS = -Wall -Wextra -Werror
MK_MLX = minilibx-linux
MAIN = main.c
CC = gcc -g

CFILES = atoi_hex.c \
	bresenham2.c \
	data_init.c \
	draw_map.c \
	read_map.c \
	error.c \
	fdf_utils.c \
	fdf_utils_map.c \
	isometry.c \
	mp_colors.c \
	stock_z.c \

MK_PRINTF = ./ft_printf/libftprintf.a

OFILES = $(CFILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MK_PRINTF):
	cd ft_printf/ && make && cd ..


$(NAME): $(MK_PRINTF) $(OFILES) $(MAIN)
	make -C $(MK_MLX)
	$(CC) $(CFLAGS) $(OFILES) $(MAIN) -Lft_printf -lftprintf -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make clean -C $(MK_MLX)
	rm -f $(OFILES)
	cd ft_printf/ && make clean && cd ..
	cd libft/ && make clean
	
fclean: clean
	cd ft_printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..
	rm -f $(NAME)

re: fclean all
