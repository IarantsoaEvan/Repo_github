/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:29:11 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/30 09:29:13 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// because arg always arrives as a string even without "" 
static long	ft_atl(const char *str)
{
	size_t	i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	multipli_same(ts_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	add_nd(ts_node **a, av + 1, error)
{
	long	nbr,
	int	idx;

	while (av[idx])
	{
		nbr = ft_atl(av[i]);
		if (nbr < -2147483648 || nbr > 2147483647)
			free_error(a, av, state_ac);
		if (multipli_same(*a, (int)nbr))
			free_error(a, av, state_error);
		add_nd(*a, (int)nbr);
	}
}
