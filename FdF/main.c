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

int key_press(int key, void *data)
{
	printf("%d", key);
	return(0);
}

int main(int ac, char **av)
{
	t_matrix	*data;

	data = (t_matrix*)malloc(sizeof(t_matrix));
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1100, 1000, "FDF");
	data->zoomer = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, key_press, NULL);
	mlx_loop(data->mlx_ptr);
	return (0);
}
