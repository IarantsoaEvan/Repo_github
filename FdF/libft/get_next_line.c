/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:41:36 by irabesan          #+#    #+#             */
/*   Updated: 2024/03/21 08:41:37 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join(char *stck, char *buff)
{
	if (stck == NULL)
		return (ft_strdup(buff));
	stck = ft_strjoin(stck, buff);
	return (stck);
}

char	*stck_buff(int fd, char *stck)
{
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		stck = join(stck, buff);
		if (ft_found_nl(stck, '\n') == 'F')
			break ;
	}
	free(buff);
	return (stck);
}

char	*ft_left(char *stck)
{
	int		i;
	int		l;
	char	*str_line;

	i = 0;
	l = 0;
	while (stck[l] && stck[l] != '\n')
		l++;
	str_line = (char *)malloc(sizeof(char) * (l + 2));
	if (!str_line)
		return (NULL);
	while (i <= l)
	{
		str_line[i] = stck[i];
		i++;
	}
	str_line[i] = '\0';
	return (str_line);
}

char	*ft_right(char *stck)
{
	int		i;
	size_t	l;
	char	*new_stck;

	i = 0;
	l = 0;
	while (stck[l] && stck[l] != '\n')
		l++;
	if (stck[l] == '\n')
		l++;
	new_stck = (char *)malloc (sizeof(char) * (ft_strlen(stck) - l + 1));
	if (!new_stck)
	{
		free(stck);
		return (NULL);
	}
	while (l < ft_strlen(stck))
		new_stck[i++] = stck[l++];
	new_stck[i] = '\0';
	free(stck);
	stck = NULL;
	return (new_stck);
}

char	*get_next_line(int fd)
{
	static char	*st_line;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	st_line = stck_buff(fd, st_line);
	if (st_line == NULL || *st_line == 0)
	{
		free(st_line);
		st_line = NULL;
		return (NULL);
	}
	line = ft_left(st_line);
	if (!line)
	{
		free(st_line);
		st_line = NULL;
		return (NULL);
	}
	st_line = ft_right(st_line);
	return (line);
}
