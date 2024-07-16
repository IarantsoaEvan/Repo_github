/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:18:59 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/16 16:19:01 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_new_stack(t_lkl **root, t_lkl *n_root)
{
	if (root && n_root)
	{
		if (!(*root))
			*root = n_root;
		else
		{
			n_root->next = *root;
			*root = n_root;
		}
	}
}

int	fill_z_stk(char **z_split, t_lkl **stack)
{
	t_lkl	*nz_stck;

	nz_stck = (t_lkl *)malloc(sizeof(t_lkl));
	if (!nz_stck)
		return (1);
	nz_stck->z = (t_zz *)malloc(sizeof(t_zz));
	if (!(nz_stck->z))
		return (1);
	nz_stck->z->relief = ft_atoi(z_split[0]);
	if (z_split[1] != NULL)
		nz_stck->z->color = ft_atoi_hex(z_split[1]);
	else
		nz_stck->z->color = -1;
	nz_stck->next = NULL;
	add_new_stack(stack, nz_stck);
	return (0);
}
