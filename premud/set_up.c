/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:02:15 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/24 13:46:19 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_philo *philo, char **av)
{
	philo->philo_nbr = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->num_times_to_eat = ft_atoi(av[5]);
	else
		philo->num_times_to_eat = -3;
}
void	init_philos(t_philo *philos, t_schedule *program, pthread_mutex_t *forks,
			char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], av);
		philos[i].reel_start = ft_get_current_time();
		philos[i].last_meal = ft_get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].philo_nbr - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
		
	}
}
void	init_forks(pthread_mutex_t *forks, int	philo_nbr)
{
	int	i;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
void	init_schedule(t_schedule *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	ft_annihilizer(t_schedule *pgr, t_philo *pfk, char *m_error)
{
	int	k;

	k = -1;
	if (m_error)
	{
		write(STDERR_FILENO, m_error, ft_strlen(m_error));
		write(STDERR_FILENO, "\n", 1);
	}
	while (++k < pgr->philos[0].philo_nbr)
		pthread_mutex_destroy(&pfk[k]);
	pthread_mutex_destroy(&pgr->write_lock);
	pthread_mutex_destroy(&pgr->dead_lock);
	pthread_mutex_destroy(&pgr->meal_lock);
	return ;
}
