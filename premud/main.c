/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:06:01 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/21 13:07:03 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	check_av(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0
		|| check_av(av[1]) == 1)
		return (print_error(1), 1);
	if (ft_atoi(av[2]) <= 0 || check_av(av[2]) == 1)
		return (print_error(2), 1);
	if (ft_atoi(av[3]) <= 0 || check_av(av[3]) == 1)
		return (print_error(3), 1);
	if (ft_atoi(av[4]) <= 0 || check_av(av[4]) == 1)
		return (print_error(4), 1);
	if (av[5] && (ft_atoi(av[5]) < 0 || check_av(av[1]) == 1))
		return (print_error(5), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_program	program;
	t_philo	philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac != 5 && ac != 6)
		return (print_error(6), 1);
	if (check_input(av) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
  return (0);
}
