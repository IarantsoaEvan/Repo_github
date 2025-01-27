/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:13:50 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/09 11:13:51 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	per_iso(int *x, int *y, int z, double teta)
{
	int	tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(teta);
	*y = (tmp + *y) * sin(teta) - z;
}

void	x_rotation(int *x, int *y, int *z, double teta)
{
	int	tmp;

	(void)(x);
	tmp = *y;
	*y = tmp * cos(teta) + *z * sin(teta);
	*z = -(tmp) * sin(teta) + *z * (cos(teta));
}

void	y_rotation(int *x, int *y, int *z, double teta)
{
	int	tmp;

	(void)(y);
	tmp = *x;
	*x = tmp * cos(teta) + *z * sin(teta);
	*z = -(tmp) * sin(teta) + *z * (cos(teta));
}

void	z_rotation(int *x, int *y, int *z, double teta)
{
	int	tmp;

	(void)(z);
	tmp = *x;
	*x = tmp * cos(teta) - *y * sin(teta);
	*y = -(tmp) * sin(teta) + *y * (cos(teta));
}
