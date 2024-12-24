/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:28:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/24 12:44:46 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_daily_routine(void *ff)
{
	t_philo	*philo;

	philo = (t_philo *)ff;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while(!dead_loop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ff);
}
int	ft_create_th_mtx(t_schedule *pgr, pthread_mutex_t *fks)
{
	pthread_t	the_monitor;

	if (pthread_create(&the_monitor, NULL, ft_daily_routine, philo) != 0)


}