/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hnd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:33:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/23 10:33:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	close_win(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}*/

int	key_zoomer(int key, t_fdf *data)
{
	if (key == 61)
	{
		data->zoomer += 3;
		data->x_p -= 10;
		data->y_p -= 10;
	}
	else if (key == 45)
	{
		data->zoomer -= 3;
		data->x_p += 10;
		data->y_p += 10;
	}
	else if (key == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	do_rot(int key, t_fdf *data)
{
	if (key == 65362)
		data->y_p -= 15;
	else if (key == 65364)
		data->y_p += 15;
	else if (key == 65361)
		data->x_p -= 15;
	else if (key == 65363)
		data->x_p += 15;
	else if (key == 120)
	{
		data->rot = 1;
		data->alpha += 0.3;
	}
	else if (key == 121)
	{
		data->rot = 2;
		data->beta += 0.3;
	}
	else if (key == 122)
	{
		data->rot = 3;
		data->teta += 0.3;
	}
	return (0);
}

int	expose_relief(int key, t_fdf *data)
{
	if (key == 65451)
		data->relief += 2;
	else if (key == 65453)
		data->relief -= 2;
	else if (key == 65433)
		data->trans = 1;
	else if (key == 65435)
		data->trans = 0;
	return (0);
}

int	do_event(int key, t_fdf *data)
{
	key_zoomer(key, data);
	do_rot(key, data);
	expose_relief(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	param->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	draw_the_thing(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win->ptr); \
			data->img_ptr, 0, 0);
		return (0);
}
