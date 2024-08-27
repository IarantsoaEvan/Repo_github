/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:42:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/20 15:42:12 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
#define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t	thread;
	int		id;
	int		eating;
	int		meals_eaten;
	size_t		last_meal;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		reel_start;
	int		philo_nbr;
	int		num_times_to_eat;
	int		*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	
}	t_philo;

typedef struct s_program
{
	int	dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo		*philos;
}	t_program;

void  print_error(int error);
size_t	ft_get_current_time(void);
int	ft_strlen(char *str);
int ft_atoi(char *str);
void	init_input(t_philo philo, char **av);
void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks,
			char **av);
void	init_forks(pthread_mutex_t *forks, int	philo_nbr);
void	init_program(t_program *program, t_philo *philos);

#endif
