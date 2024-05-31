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
	size_t		i;
	int			sign;
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

int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_av_isdigit(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (ft_is_space(av[i]) == 1)
			return (0);
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 1 || (av[i][j] == ' ')
			|| ((av[i][j] == '-' || av[i][j] == '+')
			&& ft_isdigit(av[i][j + 1]) == 1))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	dupli_same(t_node *a, int nbr)
{
	t_node	*temp;

	if (!a)
		return (0);
	temp = a;
	while (temp)
	{
		if (temp->data == nbr)
			return (1);
		temp = temp->next;
	}
	return (0);
}
