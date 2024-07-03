/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:52:05 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/21 12:52:07 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*l1;
	unsigned char	*l2;
	size_t			i ;

	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && l1[i] == l2[i] && l1[i] != '\0' && l2[i] != '\0')
		i++;
	return (l1[i] - l2[i]);
}
/*int main() {
    char s1[] = "bonjour";
    char s2[] = "bonsoir";
    int p = ft_strncmp(s1,s2, 4);
    printf("%d",p);
    return 0;
}*/
