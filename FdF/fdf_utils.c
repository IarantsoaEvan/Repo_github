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

void	my_mlx_pxp(t_fdf *fdf, int x, int y)
{
	char	*img_ptr;

	if((x >= 0 && x < fdf->width) && (y >= 0 && y < fdf->height))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				,&fdf->bpp, &fdf->size_line, &fdf->endian);
		img_ptr = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 8));
		*(unsigned int *)img_ptr = fdf->color;
	}
}

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
