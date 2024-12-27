/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:28:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/27 13:39:56 by irabesan         ###   ########.fr       */
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
	int	k;

	if (pthread_create(&the_monitor, NULL, &the_moni, pgr->philos) != 0)
		ft_annihilizer(pgr, fks, "none creation of thread");
	k = 0;
	while (k < pgr->philos[0].philo_nbr)
	{
		if (pthread_create(&pgr->philos[k].thread, NULL, &ft_daily_routine, &pgr->philos[k]) != 0)
			ft_annihilizer(pgr, fks, "none creation of thread");
		k++;
	}
	k = 0;
	if (pthread_join(the_monitor, NULL) != 0)
		ft_annihilizer(pgr, fks, "pthr_join error");
	while (k < pgr->philos[0].philo_nbr)
	{
		if (pthread_join(pgr->philos[k].thread, NULL) != 0)
			ft_annihilizer(pgr, fks, "pthr_join error");
		k++;
	}
	return (0);
}