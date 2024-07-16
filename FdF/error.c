/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:12:17 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/16 09:12:18 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(int error)
{

	if (error == 1)
		ft_printf("file error!\n");
	else if (error == 2)
		ft_printf("invalid parameters!\n");
	else if (error == 3)
		ft_printf("allocation error!\n");
	else if (error == 4)
		ft_printf("found wrong line length exiting!\n");
	exit(1);
}

int	ft_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'f')
	{
		print_error(1);
		exit(1);
	}
	return (0);
}
