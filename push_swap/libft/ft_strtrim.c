/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:46:07 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/23 07:46:11 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bgn;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		bgn = 0;
		end = ft_strlen(s1);
		while (s1[bgn] != '\0' && ft_strchr(set, s1[bgn]))
			bgn++;
		while (s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]) && bgn < end)
			end--;
		str = (char *)malloc((end - bgn + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[bgn], end - bgn + 1);
	}
	return (str);
}
/*int main ()
{
	char const *s1 = "yes its a test, hello word. yes";
	char const *set = "yes";
	char *p = ft_strtrim(s1, set);
	printf("%s", p);
	return (0);
}*/
