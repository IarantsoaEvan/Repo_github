/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:20:04 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/31 11:53:59 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_is_space(av[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}
char	**ft_join_av(char **av)
{
	int	j;
	char	*str;
	char	**new_str;

	j = 2;
	str = ft_strdup(av[1]);
	while (av[j] != NULL)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[j++]);
	}
	new_str = ft_split(str, ' ');
	free(str);
	return (new_str);
}

int	ft_is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_len(t_node *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	sort_three(t_node **lst)
{
	t_node	*great_nd;
	//t_node *tmp;

	great_nd = find_max(*lst);
	if (great_nd == *lst)
		ra(lst);
	else if ((*lst)->next == great_nd)
		rra(lst);
	if ((*lst)->data > (*lst)->next->data)
		sa(lst);
	// tmp = (*lst);
	// while (tmp)
	// {
	// 	printf("Nombre = %d , Cible = %d, Median = %d, index = %d\n",tmp->data, tmp->target->data, tmp->above_med, tmp->curr_pos);
	// 	tmp = tmp->next;
	// }
}
