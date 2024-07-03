/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:49:42 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/11 10:49:44 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len1(unsigned long n)
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

static void	ft_putnbr_base_16_1(unsigned long nbr, char *base)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_16_1(nbr / 16, base);
		ft_putnbr_base_16_1(nbr % 16, base);
	}
	else
		ft_print_char(base[nbr]);
}

int	ft_print_hex1(unsigned long nbr, char t)
{
	char	*base;

	if (t == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_putnbr_base_16_1(nbr, base);
	return (hexa_len1(nbr));
}

int	ft_print_p(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len = ft_print_str("(nil)");
		return (len);
	}
	len += ft_print_str("0x");
	len += ft_print_hex1(ptr, 'x');
	return (len);
}
