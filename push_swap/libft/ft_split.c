/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:09:08 by irabesan          #+#    #+#             */
/*   Updated: 2024/02/23 12:09:11 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_w(char const *s, char c)
{
	size_t	tokens;
	size_t	i;
	size_t	j;
	int		condition;

	i = 0;
	j = 0;
	tokens = 0;
	condition = 0;
	while (s[i] == c)
		i++;
	j = i;
	while (s[j] != '\0')
	{
		if (s[j] != c && condition == 0)
		{
			condition = 1;
			tokens++;
		}
		else if (s[j] == c)
			condition = 0;
		j++;
	}
	return (tokens);
}

static char	*paste_w(char const *str, size_t len)
{
	char	*str1;

	str1 = (char *)malloc((len + 1) * sizeof(char));
	if (!str1)
	{
		free(str1);
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

	str = (char **)malloc((ft_count_w(s, c) + 1) * sizeof(char *));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	final = stock_new_arr(str, s, c);
	if (!final)
	{
		free(final);
		return (NULL);
	}
	return (final);
}
