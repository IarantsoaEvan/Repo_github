/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:45:11 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/20 12:45:15 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (size < len1)
		return (len2 + size);
	if (size > len1 + 1)
	{
		while (src[i] != '\0' && len1 + 1 + i < size)
		{
			dst[len1 + i] = src[i];
			i++;
		}
		dst[len1 + i] = '\0';
	}
	return (len1 + len2);
}
/*int main()
{
    char dst[14] = "hello";
    char src[14] = "world";
    size_t p = ft_strlcat(dst, src, 5);
    printf("%ld \n", p);
    printf("%ld", strlcat(dst, src,2));
}*/
