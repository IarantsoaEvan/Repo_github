/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:08:19 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/15 11:08:20 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
float	ft_abs(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	ft_zoomer(float *x1, float *x2, float *y1, float *y2, t_fdf *data)
{
	*x1 *= data->zoomer;
	*x2 *= data->zoomer;
	*y1 *= data->zoomer;
	*y2 *= data->zoomer;
}

void	ft_gapper(float *x1, float *x2, float *y1, float *y2, t_fdf *data)
{
	*x1 += data->gap_x;
	*x2 += data->gap_x;
	*y1 += data->gap_y;
	*y2 += data->gap_y;
}
*/
/*void	my_mlx_pxp(t_fdf *fdf, int x, int y)
{
	char	*img_ptr;

	if((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				,&fdf->bpp, &fdf->size_line, &fdf->endian);
		img_ptr = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 8));
		*(unsigned int *)img_ptr = fdf->color;
	}
}*/
int key_press(int key, t_fdf *data)
{
	ft_printf("%d\n", key);
	if (key == 65362)
		data->gap_y -= 15;
	if (key == 65364)
		data->gap_y += 15;
	if (key == 65361)
		data->gap_x -= 15;
	if (key == 65363)
		data->gap_x += 15;
	if(key == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	if (key == 113)
		data->zoomer += 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_the_thing(data);
	if (key == 32)
		data->zoomer -= 1;
	return(0);
}
