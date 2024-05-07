/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_set_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:29:11 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/02 16:01:15 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

ts_node	*whos_last(ts_node *root)
{
	if (root == NULL)
		return (NULL);
	while (root->next)
		root = root->next;
	return (root);
}

void	add_nd(ts_node *stack, int nbr)
{
	ts_node	*node;
	ts_node	*last_nd;

	if (!stack)
		return ;
	node = malloc(sizeof(ts_node));
	if (!node)
		return ;
	node->data = nbr;
	node->next = NULL;
	if (!stack)
	{
		*stack = *node;
		node->prev = NULL;	
	}
	else
	{
		last_nd = whos_last(stack);
		last_nd->next = node;
		node->prev = last_nd;
	}
}
int	set_up(ts_node **a, char **av)
{
	long	nbr;
	int	idx;

	idx = 0;
	while (av[idx])
	{
		if (ft_isdigit(av))
			return (1);
		nbr = ft_atl(av[idx]);
		if (nbr < -2147483648 || nbr > 2147483647)
			return (1);
		if (dupli_same(*a, (int)nbr))
			return (1);
		add_nd(*a, (int)nbr);
		idx++;
	}
	return (0);
}
