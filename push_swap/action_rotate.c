/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:03:54 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/13 10:04:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **a)
{
	t_node	*tmp;
	t_node *last_node;

	if (!a || *a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node = whos_last(*a);
	last_node->next = tmp;
	tmp->next = NULL;
	tmp->prev = last_node;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

