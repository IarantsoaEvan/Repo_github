/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:42:10 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/27 13:48:59 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			reel_start;
	int				philo_nbr;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;

}					t_philo;

typedef struct s_schedule
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_schedule;

void				print_error(int error);
size_t				ft_get_current_time(void);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
void				init_input(t_philo *philo, char **av);
void				init_philos(t_philo *philos, t_schedule *program,
						pthread_mutex_t *forks, char **av);
void				init_forks(pthread_mutex_t *forks, int philo_nbr);
void				init_schedule(t_schedule *program, t_philo *philos);
void				print_action(char *str, t_philo *philo, int id);
int					ft_usleep(size_t msec);
void				ft_think(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_eat(t_philo *philo);
int					dead_loop(t_philo *philo);
int					one_passed_away(t_philo *philo, size_t time_to_die);
void				*the_moni(void *ff);
void				*ft_daily_routine(void *ff);
void				ft_annihilizer(t_schedule *pgr, pthread_mutex_t *pfk,
						char *m_error);
int					ft_create_th_mtx(t_schedule *pgr, pthread_mutex_t *fks);

#endif
