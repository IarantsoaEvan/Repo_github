/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:03:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/24 14:42:53 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int 	flight_of_death(t_philo *philos)
{
	int	dth;

	dth = -1;
	while (++dth < philos[0]->philo_nbr)
	{
		if (one_passed_away(&philos[dth], philos[dth].time_to_die))
		{
			print_action("died", &philos[dth], philos[dth].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);

		}
	}
	return (0);

}
void	print_action(char *str, t_philo *philo, int id) // print message
{
	long	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_current_time() - philo->reel_start;
	if (!dead_loop(philo))
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	*the_moni(void *ff)
{
	t_philo *philo;

	philo = (t_philo *)ff;
	while(1)
		if (flight_of_death == 1 || )
}
