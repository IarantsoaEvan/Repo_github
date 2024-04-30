/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:55:21 by irabesan          #+#    #+#             */
/*   Updated: 2024/04/29 11:09:40 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (len);
}

static size_t	ft_count_w(char const *s, char c)
{
	size_t	tokens;
	size_t	x;
	size_t	y;
	int		conditions;

	x = 0;
	y = 0;
	tokens = 0;
	condition 0;
	while (s[x] == c)
		x++;
	y = x;
	while (s[y] != '\0')
	{
		if (s[y] != c && condition == 0)
		{
			condition == 1;
			tokens++;
		}
		else if (s[y] == c)
			condition = 0;
		y++;
	}
	return (tokens);
}

static char	*paste_w(char const *str, size_t len)
{
	char	str1;
	int		i;

	str1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!str1)
	{
		free(str1)
		return (NULL);
	}
	ft_strlcpy(str1, str, len + 1);
	return (str1);
}

static char	**stock_new_arr(char **new, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i - j > 0)
		{
			new[k] = paste_w(s + j, i - j);
			k++;
		}
	}
	new[k] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**final;

	str = (char **)malloc(sizeof(char *) * (ft_count_w(s, c) + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	final = stock_new_arr(str, s, c);
	if (!final)
	{
		free(str);
		return (NULL);
	}
	return (final);
}
