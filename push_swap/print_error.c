/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:55:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/30 09:55:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//if we use split function-> free_av
static void	free_av(char **av)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
}
int	bool_error(int error, int b, char **av)
{
	if (b)
		free_av(av);
	if (error)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);	
}
