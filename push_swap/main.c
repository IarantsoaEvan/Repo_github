/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:52:16 by irabesan          #+#    #+#             */
/*   Updated: 2024/05/09 12:38:16 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int	error;
	char	**str_av;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (first_check(av) == 1)
	{
		ft_printf("error\n");
		return (1);
	
	}
	else if (ac >= 2)
		str_av = ft_join_av(av);
	else
		str_av = ft_join_av(av);
	error = set_up(&a, str_av);
	if (!(ft_is_sorted(a)) || (!(bool_error(error, ac == 2, str_av))))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_1(&a, &b);
			
	}
	return (0);
}
