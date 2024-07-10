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

typedef struct	s_matrix
{
	int	width;
	int	height;
	int	**z_matrix;
	int	zoomer;
	int	color;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_matrix;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*stck_buff(int fd, char *stck);
char	*ft_left(char *stck);
char	*ft_right(char *stck);
char	*get_next_line(int fd);
char	ft_found_nl(char *stck, char c);
float	max_delta(float delta_x, float delta_y);
float	ft_abs(float i);
void	bresenham(float x1, float y1, float x2, float y2, t_matrix *data);
int	get_width(char *file);
int	get_height(char *file);
void	fill_matrix(int *z_line, char *line);
void read_file(char *file, t_matrix *data);
char	*stck_buff(int fd, char *stck);
char	*ft_left(char *stck);
char	*ft_right(char *stck);
char	*get_next_line(int fd);
char	ft_found_nl(char *stck, char c);
size_t	ft_strlen_1(const char *str);
char	*ft_strjoin_1(char *s1, char *s2);
char	*ft_strdup_1(char *src);
void	draw(t_matrix *data);
int choose_color(int z, int color);
void	per_iso(float *x, float *y, float z);

#endif
