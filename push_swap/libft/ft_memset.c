/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:13:06 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/19 13:39:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pt, int c, size_t lengh)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)pt;
	while (i < lengh)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (pt);
}
