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

void	per_iso(float *x, float *y, float z, double teta)
{
	*x = (*x - *y) * cos(teta);
	*y = (*x + *y) * sin(teta) - z;
}

void x_rotation(float *x, float *y, float *z, double teta)
{
	(void)(x);
	*y = *y * cos(teta) + *z * sin(teta);
	*z = -(*y) * sin(teta) + *z * (cos(teta));
}

void y_rotation(float *x, float *y, float *z, double teta)
{
	(void)(y);
	*x = *x * cos(teta) + *z * sin(teta);
	*z = -(*x) * sin(teta) + *z * (cos(teta));
}

void z_rotation(float *x, float *y, float *z, double teta)
{
	(void)(z);
	*x = *x * cos(teta) - *y * sin(teta);
	*y = -(*x) * sin(teta) + *y * (cos(teta));
}
