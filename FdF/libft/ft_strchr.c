/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:42:26 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/21 07:42:27 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	occur;
	int		i;

	i = 0;
	occur = (char)c;
	while (str[i] != '\0' && occur != str[i])
		i++;
	if (occur == str[i])
		return ((char *)(str + i));
	return (NULL);
}
/*int main()
{
	const char *str = "karakory";
	int c = 111;
	char *p = ft_strchr(str, c);
	printf("%s", p);
	return (0);
}*/
