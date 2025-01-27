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
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# define D_ANG 0.5
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_zz
{
	int	relief;
	int	color;

}	t_zz;

typedef struct s_lkl
{
	t_zz			*z;
	struct s_lkl	*next;
}	t_lkl;

typedef struct s_matrix
{
	t_zz	z;
}	t_matrix;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
	t_matrix	**matrix;
	t_lkl		*stack;
	int			width;
	int			height;
	int			zoomer;
	int			color;
	int			x_p;
	int			y_p;
	int			bpp;
	int			size_line;
	int			endian;
	int			relief;
	int			trans;
	int			rot;
	int			off_x;
	int			off_y;
	double		angle;
	double		alpha;
	double		beta;
	double		teta;
}	t_fdf;

typedef struct s_param
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e_2;
	int		trgb;
	float	red0;
	float	green0;
	float	blue0;
	float	ld;
	float	step_red;
	float	step_green;
	float	step_blue;
}	t_param;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

t_matrix	**ft_matrix(t_fdf *fdf, t_lkl *stack);
char		*stck_buff(int fd, char *stck);
char		*ft_left(char *stck);
char		*ft_right(char *stck);
char		*get_next_line(int fd);
char		ft_found_nl(char *stck, char c);
char		*stck_buff(int fd, char *stck);
char		*ft_left(char *stck);
char		*ft_right(char *stck);
char		*get_next_line(int fd);
char		ft_found_nl(char *stck, char c);
size_t		ft_strlen_1(const char *str);
char		*ft_strjoin_1(char *s1, char *s2);
char		*ft_strdup_1(char *src);
int			ft_is_hexadecimal(char c);
int			ft_atoi_hex(char *s);
int			ft_ccmp(int j, int k);
t_param		*init_pr(t_point *a, t_point *b);
void		bresenham_2(t_fdf *fdf, t_point *a, t_point *b);
t_point		*point_init(int x, int y, t_fdf *fdf);
t_point		*project(t_point *p, t_fdf *fdf);
void		ft_x_px(t_fdf *fdf, int x, int y);
void		ft_y_px(t_fdf *fdf, int x, int y);
void		draw_the_thing(t_fdf *fdf);
void		print_error(int error);
void		ft_change_col(t_param *param);
void		free_param(t_point *a, t_point *b, t_param *param);
int			ft_filename(char *filename);
void		my_mlx_pxp(t_fdf *fdf, int x, int y, int color);
int			key_press(int key, t_fdf *data);
void		free_split(char **split);
int			parsing_error(int width, int i, int *check_fd, char **split);
void		per_iso(int *x, int *y, int z, double teta);
void		x_rotation(int *x, int *y, int *z, double teta);
void		y_rotation(int *x, int *y, int *z, double teta);
void		z_rotation(int *x, int *y, int *z, double teta);
void		fill_data(t_matrix *matrix, t_lkl **stack, t_fdf *fdf);
int			parsing_info(char *line, t_lkl **stack, int *width, int *set_fd);
int			fill_z_stk(char **z_split, t_lkl **stack);
t_lkl		*read_file(int fd, int *width, int *height, int *set_fd);
void		add_new_stack(t_lkl **root, t_lkl *n_root);
void		free_matrix(t_fdf *fdf);
int			close_win(t_fdf *data);
int			ft_esc(int key, t_fdf *data);
int			key_zoomer(int key, t_fdf *data);
int			do_rot(int key, t_fdf *data);
int			expose_relief(int key, t_fdf *data);
int			do_event(int key, t_fdf *data);
int			ft_gradient(int x, int y, t_point *a, t_point *b);
int			create_trgb(int r, int g, int b);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
float		fraction(float x1, float x2, float x);
float		def_fract(float x, float y, t_point *s, t_point *end);

#endif
