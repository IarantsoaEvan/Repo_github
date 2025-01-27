/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:57:33 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/24 16:57:35 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

float	def_fract(float x, float y, t_point *s, t_point *end)
{
	int		dx;
	int		dy;
	float	fraact;

	dx = end->x - s->x;
	dy = end->y - s->y;
	if (abs(dx) > abs(dy))
		fraact = fraction(s->x, end->x, x);
	else
		fraact = fraction(s->y, end->y, y);
	return (fraact);
}

int	ft_gradient(int x, int y, t_point *s, t_point *end)
{
	int		trgb;
	int		r;
	int		g;
	int		b;
	float	fraact;

	fraact = def_fract((float)x, (float)y, s, end);
	r = get_r(s->color) + (get_r(end->color) - get_r(s->color)) * fraact;
	g = get_g(s->color) + (get_g(end->color) - get_g(s->color)) * fraact;
	b = get_b(s->color) + (get_b(end->color) - get_b(s->color)) * fraact;
	trgb = create_trgb(r, g, b);
	return (trgb);
}
