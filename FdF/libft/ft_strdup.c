/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:18:19 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/22 12:18:21 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	char	*csrc;

	csrc = (char *)src;
	i = ft_strlen(csrc);
	i = i + 1;
	dup = malloc(i * sizeof(char));
	if (!dup)
	{
		dup = NULL;
		return (0);
	}
	i = 0;
	while (csrc[i] != '\0')
	{
		dup[i] = csrc[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
