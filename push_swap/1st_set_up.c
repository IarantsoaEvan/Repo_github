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
void	set_up(ts_node **a, char **av, int error)
{
	long	nbr;
	int	idx;

	while (av[idx])
	{
		nbr = ft_atl(av[idx]);
		if (ft_isdigit(av))
			bool_error(error, ac == 2, av);
		if (nbr < -2147483648 || nbr > 2147483647)
			bool_error(error, ac == 2, av);
		if (dupli_same(*a, (int)nbr))
			bool_error(error, ac == 2, av);
		add_nd(*a, (int)nbr);
		idx++;
	}
}
