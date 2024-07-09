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

int choose_color(int z, int color)
{
	if (z > 0)
		color = 0xe80c0c;
	else
		color = 0xffffff;
	return (color);
}
float	max_delta(float delta_x, float delta_y)
{
	if (delta_x > delta_y)
		return (delta_x);
	else
		return (delta_y);
}

float	ft_abs(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}
void	bresenham(float x1, float y1, float x2, float y2, t_matrix *data)
{
	float	delta_x;
	float	delta_y;
	int	max;
	int	z1;

	z1 = data->z_matrix[(int)y1][(int)x1];
	//=========color=========
	data->color  = choose_color(z1, data->color);
	//=========zoom==========
	x1 *= data->zoomer;
	x2 *= data->zoomer;
	y1 *= data->zoomer;
	y2 *= data->zoomer;
	//========3D=============
	
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

void	draw(t_matrix *data) // draw all lines
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
