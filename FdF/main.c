/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:06:23 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/03 09:06:27 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_press(int key, void *data)
{
	printf("%d", key);
	return(0);
}

int main(int ac, char **av)
{
	t_matrix	*data;
	int	i;
	int	j;

	i = 0;

	data = (t_matrix*)malloc(sizeof(t_matrix));
	read_map(av[1], data);
	while (i <)
}
