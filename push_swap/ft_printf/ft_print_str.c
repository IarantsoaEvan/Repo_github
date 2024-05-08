/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:21:40 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/08 11:21:41 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}
