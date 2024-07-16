/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:04:31 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/16 16:04:34 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_hexadecimal(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'B' || c == 'b')
		return (11);
	else if (c == 'C' || c == 'c')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'F' || c == 'f')
		return (15);
	return (c - '0');
		
}

int	ft_atoi_hex(char *s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i] == '0' || s[i] == 'x')
		i++;
	while (s[i])
	{
		result *= 16 + ft_is_hexadecimal(s[i]);
		i++;
	}
	return (result);
}
