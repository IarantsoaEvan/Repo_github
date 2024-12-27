/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:01:41 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/27 11:44:40 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	print_action("is thinking", philo, philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_action("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_action("has taken a fork", philo, philo->id);
	if (philo->philo_nbr == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_action("has taken a fork", philo, philo->id);
	philo->eating = 1;
	print_action("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
