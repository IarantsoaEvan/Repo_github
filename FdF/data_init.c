/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:17:16 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/15 14:17:17 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*point_init(int x, int y, t_fdf *fdf)
{
	t_point	*data;

	data = (t_point *)malloc(sizeof(t_point));
	if (!data)
		return (NULL);
	data->x = x - fdf->off_x;
	data->y = y - fdf->off_y;
	data->z = fdf->matrix[y][x].z.relief * fdf->relief;
	data->color = fdf->matrix[y][x].z.color;
	return (data);
}
