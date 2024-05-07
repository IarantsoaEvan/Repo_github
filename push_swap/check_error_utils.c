/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:22:12 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/02 12:22:12 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// because arg always arrives as a string even without "" 
long	ft_atl(const char *str)
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

int	ft_isdigit(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while(av[i])
	{
		if((av[i][j] > '0' && av[i][j] < '9')
		 || (av[i][j] == '-' && av[i][j + 1] > '0' && av[i][j] < '9'))
			j++;
		else
			return (0);
	}
	return (1);
}

int	dupli_same(ts_node *a, int nbr)
{
	if (!a)
		return (1);
	while (a)
	{
		if (a->data == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
