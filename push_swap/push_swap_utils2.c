/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:55:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/27 12:55:40 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	max_node = NULL;

	if (!stack)
		return (NULL);
	max = -2147483648;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);	
}

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	min = 2147483647;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
t_node	*chp_is_one(t_node *stack)
{
	while (stack)
	{
		if (stack->chp == 1)
			break ;
		else
			stack = stack->next;
	}
	return (stack);
}

void	rotate_square(t_node **a, t_node **b, t_node *chp)
{
	while(*a != chp && *b != chp->target)
		rr(a, b);
	curr_position(*a);
	curr_position(*b);
}

void	rr_square (t_node **a, t_node **b, t_node *chp)
{
	while (*a != chp && *b != chp->target)
		rrr(a, b);
	curr_position(*a);
	curr_position(*b);
}
