/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:52:30 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/22 12:33:10 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*project(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->zoomer;
	p->y *= fdf->zoomer;
	if (fdf->rot >= 0)
	{
		x_rotation(&p->x, &p->y, &p->z, fdf->alpha);
		y_rotation(&p->x, &p->y, &p->z, fdf->beta);
		z_rotation(&p->x, &p->y, &p->z, fdf->teta);
	}
	if (fdf->trans == 1)
		per_iso(&p->x, &p->y, p->z, fdf->angle);
	p->x += fdf->x_p;
	p->y += fdf->y_p;
	return (p);
}

void	ft_x_px(t_fdf *fdf, int x, int y)
{
	t_point	*a;
	t_point	*b;

	a = project(point_init(x, y, fdf), fdf);
	b = project(point_init(x + 1, y, fdf), fdf);
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.relief != 0)
			a->color = 0x7f00ff;
		else
			a->color = 0x00ffff;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_2(fdf, a, b);
}

void	ft_y_px(t_fdf *fdf, int x, int y)
{
	t_point	*a;
	t_point	*b;

	a = project(point_init(x, y, fdf), fdf);
	b = project(point_init(x, y + 1, fdf), fdf);
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.relief != 0)
			a->color = 0x00ffff;
		else
			a->color = 0x3299cc;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_2(fdf, a, b);
}

void	draw_the_thing(t_fdf *fdf)
{
	int	x;
	int	y;
	int	w;
	int	h;

	w = fdf->width;
	h = fdf->height;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < w - 1)
				ft_x_px(fdf, x, y);
			if (y < h - 1)
				ft_y_px(fdf, x, y);
			++x;
		}
		++y;
	}
}
