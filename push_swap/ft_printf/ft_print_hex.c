/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:08:30 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/12 10:02:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putnbr_base_16(unsigned int nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_16(nbr / 16, base);
		ft_putnbr_base_16(nbr % 16, base);
	}
	else
		ft_print_char(base[nbr]);
}

int	ft_print_hex(int nbr, char t)
{
	char			*base;
	unsigned int	c;

	if (t == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	c = (unsigned int)nbr;
	ft_putnbr_base_16(c, base);
	return (hexa_len(c));
}
