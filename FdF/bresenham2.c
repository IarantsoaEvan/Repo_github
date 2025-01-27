/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brensenham2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:51:07 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/16 09:51:12 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ccmp(int a, int b)
{
	int	value;

	if (a < b)
		value = 1;
	else
		value = -1;
	return (value);
}

void	my_mlx_pxp(t_fdf *fdf, int x, int y, int color)
{
	char	*addr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				, &fdf->bpp, &fdf->size_line, &fdf->endian);
		addr = fdf->img_data + (y * fdf->size_line + x * (fdf->bpp / 8));
		*(unsigned int *)addr = color;
	}
}

t_param	*init_pr(t_point *a, t_point *b)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		return (NULL);
	param->dx = abs(b->x - a->x);
	param->sx = ft_ccmp(a->x, b->x);
	param->dy = -abs(b->y - a->y);
	param->sy = ft_ccmp(a->y, b->y);
	param->err = param->dx + param->dy;
	param->ld = sqrt((param->dx * param->dx) + (param->dy * param->dy));
	param->step_red = (get_r(b->color) - get_r(a->color)) / param->ld;
	param->step_green = (get_g(b->color) - get_g(a->color)) / param->ld;
	param->step_blue = (get_b(b->color) - get_b(a->color)) / param->ld;
	param->red0 = get_r(a->color);
	param->green0 = get_g(a->color);
	param->blue0 = get_b(a->color);
	return (param);
}

void	bresenham_2(t_fdf *fdf, t_point *a, t_point *b)
{
	t_param	*param;

	param = init_pr(a, b);
	while (1)
	{
		param->trgb = create_trgb((int)param->red0, (int)param->green0 \
		, (int)param->blue0);
		my_mlx_pxp(fdf, a->x, a->y, param->trgb);
		if (a->x == b->x && a->y == b->y)
			break ;
		param->e_2 = 2 * param->err;
		if (param->e_2 >= param->dy)
		{
			param->err += param->dy;
			a->x += param->sx;
		}
		if (param->e_2 <= param->dx)
		{
			param->err += param->dx;
			a->y += param->sy;
		}
		ft_change_col(param);
	}
	free_param(a, b, param);
}
