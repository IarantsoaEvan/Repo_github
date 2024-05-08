/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:35:38 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/08 11:35:39 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr)
{
	size_t	len;
	char	*str_num;

	str_num = ft_itoa(nbr);
	ft_print_str(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
