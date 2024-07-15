/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:23 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/03 09:06:27 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return(0);
}

int main(int ac, char **av)
{
	t_fdf	*data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1100, 1000, "FDF");
	data->zoomer = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, key_press, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
