/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:20:54 by irabesan          #+#    #+#             */
/*   Updated: 2024/06/25 10:20:57 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_linux/mlx.h"
#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest
	
	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dest = color;
}
