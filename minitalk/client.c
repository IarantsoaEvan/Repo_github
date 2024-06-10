/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:10:30 by irabesan          #+#    #+#             */
/*   Updated: 2024/06/05 11:10:31 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ascii_to_bin(int pid, char *m_str)
{
	int	idx;
	int	byte;

	idx = 0;
	while (m_str[idx])
	{
		byte = 0;
		while (byte++ < 8)
		{
			if (((unsigned char)(m_str[idx]) >> (7 - idx) & 1) == 1)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(m_str[idx]) >> (7 - idx) & 1) == 0)
				kill(pid, SIGUSR2);
		}
	idx++;
	}
	idx = 0;
	while (idx++ <= 7)
	{
		kill(pid, SIGUSR2);
		usleep(45);
	}
	
}
int	main(int ac, char **av)
{
	char	*m_str;
	int	ids;

	if (ac == 3)
	{
		ids = ft_atoi(av[1]);
		if (!ids)
		{
			ft_printf("invalid PID\n");
			return (0);
		}
		m_str = av[2];
		if (m_str[0] == 0)
		{
			ft_printf("empty message\n");
			return (0);
		}
		ascii_to_bin(ids, m_str);
	}
	else
	{
		ft_printf("Invalid numbers of arguments\n");
		ft_printf("You must enter the PID then the message\n");
	}
}
