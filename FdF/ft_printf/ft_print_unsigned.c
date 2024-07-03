/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:42:37 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/08 11:43:05 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nbr( unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int nbr)
{
	char	*str_num;
	int		x;

	x = len_nbr(nbr);
	str_num = (char *)malloc((x + 1) * sizeof(char));
	if (!str_num)
		return (NULL);
	*(str_num + x) = '\0';
	while (x--)
	{
		*(str_num + x) = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str_num);
}

int	ft_print_unsigned(unsigned int nbr)
{
	char	*str_num;
	size_t	len;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		str_num = ft_unsigned_itoa(nbr);
	ft_print_str(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
