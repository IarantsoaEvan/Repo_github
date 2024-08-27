/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:03:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/27 12:03:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock)
	if ((*philo)->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	print_action(char *str, t_philo *philo, int id)
{
	long	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_current_time() - philo->reel_start;
	if (!dead_loop(philo))
		printf("%ld %d %s\n", time, philo->id, str);
	pthreard_mutex_umlock(philo->write_lock);
}
