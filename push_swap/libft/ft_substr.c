/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:35:35 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/22 13:35:36 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_f_alloc(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len1;

	len_s = ft_strlen(s);
	if (len > len_s - start)
		len1 = len_s - start + 1;
	if ((start + len) <= len_s)
		len1 = len + 1;
	if (start > len_s)
		len1 = 1;
	return (len1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		str_i;
	size_t		s_i;

	s_i = 0;
	str_i = 0;
	str = (char *)malloc(sizeof(char) * (len_f_alloc(s, start, len)));
	if (!str)
		return (NULL);
	while (s[s_i] != 0)
	{
		if (s_i >= start && str_i < len)
		{
			str[str_i] = s[s_i];
			str_i++;
		}
		s_i++;
	}
	str[str_i] = '\0';
	return (str);
}
/*int main() {
    char *s = "hola";
    char *p = ft_substr(s,0,18446744073709551615);
    printf("%s", p);

    return 0;
}*/
