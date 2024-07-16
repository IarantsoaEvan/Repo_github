/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:39:02 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/03 09:39:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# define ANG 0.523599
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_zz
{
	int	relief;
	int color;

}	t_zz;

typedef struct	s_lkl
{
	t_zz			*z;
	struct s_lkl	*next;
}	t_lkl;

typedef struct s_matrix
{
	t_zz	z;
}	t_matrix;

typedef struct	s_fdf
{
	int	width;
	int	height;
	int	x_p;
	int	y_p;
	int	trans;
	int	relief;
	int	**z_matrix;
	t_matrix	**matrix;
	t_lkl		*stack;
	int	zoomer;
	int	color;
	int	gap_x;
	int	gap_y;
	int	bpp;
	int	size_line;
	int	endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	double	angle;
	double	alpha;
	double	beta;
	double	teta;
}	t_fdf;

typedef struct	s_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e_2;
}	t_param;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//void	bresenham(int x1, int y1, int x2, int y2, t_fdf *data);
//void	draw(t_fdf *data);
//int	ft_abs(int i);
//void	ft_zoomer(int *x1, int *x2, int *y1, int *y2, t_fdf *data);
//void	ft_gapper(int *x1, int *x2, int *y1, int *y2, t_fdf *data);
//int	max_delta(int delta_x, int delta_y);
//void read_file(char *file, t_fdf *data);
char	*stck_buff(int fd, char *stck);
char	*ft_left(char *stck);
char	*ft_right(char *stck);
char	*get_next_line(int fd);
char	ft_found_nl(char *stck, char c);
char	*stck_buff(int fd, char *stck);
char	*ft_left(char *stck);
char	*ft_right(char *stck);
char	*get_next_line(int fd);
char	ft_found_nl(char *stck, char c);
size_t	ft_strlen_1(const char *str);
char	*ft_strjoin_1(char *s1, char *s2);
char	*ft_strdup_1(char *src);
int	ft_is_hexadecimal(char c);
int	ft_atoi_hex(char *s);
int	ft_ccmp(int j, int k);
t_param	*init_pr(t_point *a, t_point *b);
void	bresenham_2(t_fdf *fdf, t_point *a, t_point *b);
t_point	*point_init(int x, int y, t_fdf *fdf);
t_point	*project(t_point *p, t_fdf *fdf);
void	ft_x_px(t_fdf *fdf, int x, int y);
void	ft_y_px(t_fdf *fdf, int x, int y);
void draw_the_thing(t_fdf *fdf);
void	print_error(int error);
int	ft_filename(char *filename);
void	my_mlx_pxp(t_fdf *fdf, int x, int y);
int key_press(int key, t_fdf *data);
void	free_split(char **split);
int	parsing_error(int width, int i, int *check_fd, char **split);
void	per_iso(int *x, int *y, int z, double teta);
void x_rotation(int *x, int *y, int *z, double teta);
void y_rotation(int *x, int *y, int *z, double teta);
void z_rotation(int *x, int *y, int *z, double teta);
void	fill_data(t_matrix *matrix, t_lkl **stack, t_fdf *fdf);
t_matrix	**ft_matrix(t_fdf *fdf, t_lkl *stack);
int	get_width(char *file);
int	get_height(char *file);
int	parsing_info(char *line, t_lkl **stack, int *width, int *set_fd);
t_lkl *read_file(int fd, int *width, int *height, int *set_fd);
void	add_new_stack(t_lkl **root, t_lkl *n_root);
int	fill_z_stk(char **z_split, t_lkl **stack);

#endif
