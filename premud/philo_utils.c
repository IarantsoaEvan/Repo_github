/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:53:43 by irabesan          #+#    #+#             */
/*   Updated: 2024/12/21 15:04:51 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		printf("gettimeofday() error\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	unsigned long long	nbr;
	int					sign;
	int					i;

	nbr = 0;
	sign = 1;
	i = 0;
	while((str[i] >= 9  && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (sign *nbr);
}

int	ft_usleep(unsigned int msec)
{
	unsigned int	p_start;

	p_start = ft_get_current_time();
	while ((ft_get_current_time() - p_start) < msec)
		usleep(500);
	return (0);
}
