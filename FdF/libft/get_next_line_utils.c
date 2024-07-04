/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:42:18 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/14 09:42:20 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
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

size_t	ft_strlen(const char *str)
{
	size_t	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	ft_found_nl(char *stck, char c)
{
	int	i;

	if (stck == NULL)
		return ('F');
	i = 0;
	while (stck[i] != '\0')
	{
		if (stck[i] == c)
			return ('F');
		i++;
	}
	return ('N');
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (free(s1), NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}
