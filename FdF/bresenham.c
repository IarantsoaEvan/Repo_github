/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:28:17 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/04 11:28:22 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int choose_color(int z, int z1, int color)
{
	if (z > 0 || z1 > 0)
		color = 0x0000FF00;
	else
		color = 0x000000FF;
	return (color);
}
float	max_delta(float delta_x, float delta_y)
{
	if (delta_x > delta_y)
		return (delta_x);
	else
		return (delta_y);
}

void	bresenham(float x1, float y1, float x2, float y2, t_fdf *data)
{
	float	delta_x;
	float	delta_y;
	int	max;
	int	z1;
	int	z2;

	z1 = data->z_matrix[(int)y1][(int)x1];
	z2 = data->z_matrix[(int)y2][(int)x2];
	//=========zoom==========
	ft_zoomer(&x1, &x2, &y1, &y2, data);
	//=========color=========
	data->color  = choose_color(z1, z2, data->color);
	//========3D=============
	per_iso(&x1, &y1, z1, (M_PI / 6));
	per_iso(&x2, &y2, z2, (M_PI / 6));
	//=======gapper=========
	ft_gapper(&x1, &x2, &y1, &y2, data);
	delta_x = x2 - x1;
	delta_y = y2 - y1;
	max = max_delta((ft_abs(delta_x)), (ft_abs(delta_y)));
	delta_x /= max;
	delta_y /= max;
	while((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		x1 += delta_x;
		y1 += delta_y;
	}
}

void	draw(t_fdf *data) // draw all lines
{
	int	x;
	int 	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			++x;
		}
		++y;
	}
}
