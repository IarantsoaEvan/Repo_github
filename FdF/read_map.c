/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:51:25 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/03 10:51:26 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_w(char *s, char c)
{
	int	tokens;
	int	i;
	int	j;
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

int	get_width(char *file)
{
	int	width;
	int	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	width = ft_count_w(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int	get_height(char *file)
{
	int	fd;
	int	height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		
		line = get_next_line(fd);
		if (!line)
			break;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nms;
	int	k;

	k = 0;
	nms = ft_split(line, ' ');
	while (nms[k])
	{
		z_line[k] = ft_atoi(nms[k]);
		free(nms[k]);
		k++;
	}
	free(nms);
}
void	read_file(char *file, t_fdf *data)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	while(i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
