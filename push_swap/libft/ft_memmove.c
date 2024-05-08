/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:44 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/20 14:28:46 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == NULL && source == NULL)
		return (NULL);
	if ((unsigned char *)dest < (unsigned char *)source)
	{
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dest)[len - 1 - i]
				= ((unsigned char *)source)[len - 1 - i];
			i++;
		}
	}
	return (dest);
}
