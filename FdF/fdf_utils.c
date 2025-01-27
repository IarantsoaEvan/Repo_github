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

void	ft_change_col(t_param *param)
{
	param->red0 += param->step_red;
	param->green0 += param->step_green;
	param->blue0 += param->step_blue;
}

void	free_param(t_point *a, t_point *b, t_param *param)
{
	free(a);
	free(b);
	free(param);
}
