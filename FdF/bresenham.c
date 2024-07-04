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

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	max = max_delta((ft_abs(delta_x)), (ft_abs(delta_y)));
	delta_x /= max;
	delta_y /= max;
	while((int)(x1 - x2) > 0 || (int)(y1 - y2) > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, 0xffffff);
		x1 += delta_x;
		y1 += delta_y;
	}
	
}
