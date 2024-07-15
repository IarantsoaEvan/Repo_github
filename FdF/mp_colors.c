/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:40:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/15 14:40:43 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_data(t_matrix *matrix, t_lkl **stack, t_fdf *fdf)
{
	int	w;

	w = fdf->width;
	while (w--)
	{
		matrix[w].z.relief = (*stack)->z->relief;
		matrix[w].z.color = (*stack)->z->color;
		(*stack) = (*stack)->next;
	}
}

t_matrix	**ft_matrix(t_fdf *fdf, t_lkl *stack)
{
	t_matrix	**matrix;
	int		h;
	int		w;

	h = fdf->height;
	w = fdf->width;
	matrix = (t_matrix **)malloc(sizeof(t_matrix *) * (h + 1));
	if (matrix)
		return (NULL);
	while (h--)
	{
		matrix[h] = (t_matrix *)malloc(sizeof(t_matrix) * (w));
		if (!matrix[h])
			return (NULL);
		fill_data(matrix[h], &stack, fdf);
	}
	matrix[h] = NULL;
	return (matrix);
}
