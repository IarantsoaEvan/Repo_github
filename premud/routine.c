/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:01:41 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/27 12:01:42 by irabesan         ###   ########.fr       */
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
