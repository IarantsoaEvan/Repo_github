/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:52:16 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/29 12:55:41 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	ts_node	*a;
	//ts_node	*b;
	int	error;

	a = NULL;
	//b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac != 1)
		av = ft_split(av[1], ' ');
	error = set_up(&a, av + 1);
	if (bool_error(error, ac == 2, av))
		return (1);
	return (0);
}

