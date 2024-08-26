/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:37:54 by irabesan          #+#    #+#             */
/*   Updated: 2024/08/21 17:37:55 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}
static int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static const char	*check_input(const char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(*str) == 1)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		print_error(1);
	if (ft_is_digit(*str) == 1)
		print_error(2);
		
		
}
