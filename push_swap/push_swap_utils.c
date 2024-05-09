/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:20:04 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/09 15:20:06 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_av(char **av)
{
	int	j;
	char	*str;

	j = 2;
	str = ft_strdup(av[1]);
	while (av[j] != NULL)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[j++]);
	}
	return (str);
}
