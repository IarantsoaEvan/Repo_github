/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:03:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/27 13:33:03 by irabesan         ###   ########.fr       */
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

	dth = 0;
	while (dth < philos[0].philo_nbr)
	{
		if (one_passed_away(&philos[dth], philos[dth].time_to_die) == 1)
		{
			print_action("died", &philos[dth], philos[dth].id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		dth++;
	}
	return (0);

}

int	g_r_full(t_philo *philos)
{
	int	full_flag;
	int	k;

	full_flag = 0;
	k = 0;
	if (philos[0].num_times_to_eat == -3)
		return (0);
	while (k < philos[0].philo_nbr)
	{
		pthread_mutex_lock(philos[k].meal_lock);
		if (philos[k].meals_eaten >= philos[k].num_times_to_eat)
			full_flag++;
		pthread_mutex_unlock(philos[k].meal_lock);
		k++;
	}
	if (full_flag == philos[0].philo_nbr)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}
void	print_action(char *str, t_philo *philo, int id) // print message
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_current_time() - philo->reel_start;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	*the_moni(void *ff)
{
	t_philo *philos;

	philos = (t_philo *)ff;
	while (1)
		if (flight_of_death(philos) == 1 || g_r_full(philos) == 1)
			break ;
	return (ff);		
}
