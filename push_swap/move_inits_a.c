/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_inits_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:42:34 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/30 10:59:04 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	curr_position(t_node *stack)
{
	int	i;
	int	median;

	i = 0 ;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->curr_pos = i;
		if (i <= median)
			stack->above_med = 1;
		else
			stack->above_med = 0;
		stack = stack->next;
		i++;
	}
}
static void	see_target_a(t_node *a, t_node *b)
{
	t_node	*curr_b;
	t_node *target_node;
	long	target_value;

	while (a)
	{
		target_value = -2147483648;
		curr_b = b;
		while(curr_b)
		{
			if (curr_b->data < a->data
				&& curr_b->data > target_value)
			{
				target_value = curr_b->data;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (target_value == -2147483648)
			a->target  = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	see_cost_a(t_node *a, t_node *b)
{
	int	l_a;
	int	l_b;

	l_a = stack_len(a);
	l_b = stack_len(b);
	while (a)
	{
		a->push_value = a->curr_pos;
		if (!(a->above_med))
			a->push_value = l_a - (a->curr_pos);
		if (a->target->above_med)
			a->push_value += a->target->curr_pos;
		else
			a->push_value += l_b - (a->target->curr_pos);
		a = a->next;
	}
}
void	see_cheapest(t_node *stack)
{
	long	cheapest_mv;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_mv = 2147483647;
	while (stack)
	{
		if (stack->push_value < cheapest_mv)
		{
			cheapest_mv = stack->push_value;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->chp = 1;
}

void	inits_a(t_node *a, t_node *b)
{
	curr_position(a);
	curr_position(b);
	see_target_a(a, b);
	see_cost_a(a, b);
	see_cheapest(a);
}
