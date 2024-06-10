/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:01:45 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/22 11:01:49 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		delta;

	i = 0;
	while (i < n)
	{
		delta = *(const unsigned char *)s1++ - *(const unsigned char *)s2++;
		if (delta)
			return (delta);
		i++;
	}
	return (0);
}
/*int main()
{
	int arr[] = {1,2,3,4,5};
	int arr1[] = {1,2,3,5,4};
	int p = ft_memcmp(arr, arr1, 4);
	printf("%d", p);
	return (0);
}*/
