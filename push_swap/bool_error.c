/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:55:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/30 09:55:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bool_error(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	while (av[i])
	{
		if (ft_isdigit(av[i][j]) || av[i][j] == ' ' || (av[i][j]) == '-' && ft_isdigit(av[i][j + 1]))
			j++;
		else
			return (0);
	}
}
