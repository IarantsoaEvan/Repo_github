/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:52:30 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/12 13:52:32 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*project(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->zoomer;
	p->y *= fdf->zoomer;
	x_rotation(&p->x, &p->y, &p->z, fdf->alpha);
	y_rotation(&p->x, &p->y, &p->z, fdf->beta);
	z_rotation(&p->x, &p->y, &p->z, fdf->teta);
	if (fdf->trans == 1)
		per_iso(&p->x, &p->y, p->z, fdf->angle);
	p->x += fdf->x_p;
	p->y += fdf->y_p;
	return (p);
}

void	ft_x_px(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.relief != 0)
			fdf->color = 0xff0000;
		else
			fdf->color = 0xffffff;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_2(fdf,project(point_init(x, y, fdf), fdf) \
			, project(point_init(x + 1, y, fdf), fdf));
	
}

void	ft_y_px(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.relief != 0)
			fdf->color = 0xff0000;
		else
			fdf->color = 0xffffff;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_2(fdf,project(point_init(x, y, fdf), fdf) \
			, project(point_init(x , y + 1, fdf), fdf));
	
}

void draw_the_thing(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				ft_x_px(fdf, x, y);
			if (y < fdf->height - 1)
				ft_y_px(fdf, x, y);
			x++;	
		}
		y++;
	}
}
