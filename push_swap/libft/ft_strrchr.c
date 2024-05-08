/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:31:43 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/21 11:31:45 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	occur;
	int		i;

	i = ft_strlen(str);
	occur = (char)c;
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == occur)
			return ((char *)(str + i));
		i--;
	}
	return (0);
}
/*int main()
{
	const char *str = "ka rakory";
	int c = 97;
	char *p = ft_strrchr(str, c);
	printf("%s", p);
	return (0);
}*/
