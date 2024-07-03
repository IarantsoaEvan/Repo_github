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
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*stck_buff(int fd, char *stck);
char	*ft_left(char *stck);
char	*ft_right(char *stck);
char	*get_next_line(int fd);
char	ft_found_nl(char *stck, char c);
typedef struct	s_matrix
{
	int	width;
	int	height;
	int	**z_matrix;
	void	*mlx_ptr;
	void	*wind_ptr;
}	t_matrix;
#endif
