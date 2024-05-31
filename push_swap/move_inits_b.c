/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_inits_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:25:25 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/27 13:25:27 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*target_node;
	long	target_value;

	while (b)
	{
		target_value = 2147483647;
		curr_a = a;
		
		while (curr_a)
		{
			if (curr_a->data > b->data
				&& curr_a->data < target_value)
			{
				target_value = curr_a->data;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (target_value == 2147483647)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void inits_b(t_node *a, t_node *b)
{
	curr_position(a);
	curr_position(b);
	set_target_b(a, b);
}
