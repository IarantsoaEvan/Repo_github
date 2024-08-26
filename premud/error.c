/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:07:20 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/21 13:11:22 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	track_digit(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[0] == '-')
		{
			printf("args contain one or more negative numbers!\n");
			i++;
			return (1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void	print_error(int error)
{
	if (error == 1)
		printf("Invalid philosophers number!\n");
	else if (error == 2)
		printf("Invalid time to die!\n");
	else if (error == 3)
		printf("Invalid time to eat!\n");
	else if (error == 4)
		printf("Invalid time to sleep!\n");
	else if (error == 5)
		printf("Invalid number of times each philosopher must eat!\n");	
	else if (error == 6)
		printf("Wrong argument count!\n");
}
