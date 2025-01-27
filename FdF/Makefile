NAME = fdf
NAME_B = fdf_b
CFLAGS = -Wall -Wextra -Werror
MK_MLX = minilibx-linux
MAIN = main.c
MAIN_B = main_bonus.c
CC = gcc -g

CFILES = atoi_hex.c \
	bresenham2.c \
	data_init.c \
	draw_map.c \
	read_map.c \
	error.c \
	key_hnd.c \
	fdf_utils_map.c \
	fdf_utils.c \
	isometry.c \
	mp_colors.c \
	stock_z.c \
	ft_colors.c \
	ft_colors_utils.c

CFILES_B = atoi_hex.c \
	bresenham2.c \
	data_init.c \
	draw_map.c \
	read_map.c \
	error.c \
	key_hnd_bonus.c \
	fdf_utils_map.c \
	fdf_utils.c \
	isometry.c \
	mp_colors.c \
	stock_z.c \
	ft_colors.c \
	ft_colors_utils.c

MK_PRINTF = ./ft_printf/libftprintf.a

OFILES_B = $(CFILES_B:.c=.o)
OFILES = $(CFILES:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MK_PRINTF):
	cd ft_printf/ && make && cd ..


$(NAME): $(MK_PRINTF) $(OFILES) $(MAIN)
	make -C $(MK_MLX)
	$(CC) $(CFLAGS) $(OFILES) $(MAIN) -Lft_printf -lftprintf -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)


bonus: $(MK_PRINTF) $(OFILES_B) $(MAIN_B)
	make -C $(MK_MLX)
	$(CC) $(OFILES_B) $(MAIN_B) -Lft_printf -lftprintf -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME_B)

clean:
	make clean -C $(MK_MLX)
	rm -f $(OFILES) $(OFILES_B)
	cd ft_printf/ && make clean && cd ..
	cd libft/ && make clean
	
fclean: clean
	cd ft_printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..
	rm -f $(NAME) $(NAME_B)

re: fclean all
