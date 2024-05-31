/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:58:28 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/31 13:37:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	m_a_b(t_node **a, t_node **b)
{
	t_node	*chp;

	chp = chp_is_one(*a);
	if (chp->above_med && chp->target->above_med)
		rotate_square(a, b, chp);
	else if (!(chp->above_med)
		&& !(chp->target->above_med))
		rr_square(a, b, chp);
	prep_for_push(a, chp, 'a');
	prep_for_push(b, chp->target, 'b');
	pb(b, a);
}

static void	m_b_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}

static void	little_up(t_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_med)
			ra(a);
		else
			rra(a);
	}
}
void	sort_1(t_node **a, t_node **b)
{
	int	l_a;

	l_a  = stack_len(*a);
	if (l_a-- > 3 && !(ft_is_sorted(*a)))
		pb(b, a);
	if (l_a-- > 3 && !(ft_is_sorted(*a)))
		pb(b, a);
	while (l_a-- > 3 && !(ft_is_sorted(*a)))
	{
		inits_a(*a, *b);
		m_a_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		inits_b(*a, *b);
		m_b_a(a, b);
	}
	curr_position(*a);
	little_up(a);
}
