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
	int	condition;

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

int	parsing_info(char *line, t_lkl **stack, int *width, int *set_fd)
{
	char	**split;
	char	**z_split;
	int		j;

	split = ft_split(line, ' ');
	j = 0;
	while (split[j] != NULL)
	{
		z_split = ft_split(split[j], ',');
		if (fill_z_stk(z_split, stack))
		{
			free_split(z_split);
			free_split(split);
			*set_fd = -1;
			return (1);
		}
		free_split(z_split);
		j++;
	}
	if (parsing_error(*width, j, set_fd, split))
		return (1);
	return (0);
}

t_lkl	*read_file(int fd, int *width, int *height, int *set_fd)
{
	char	*line;
	t_lkl	*stack;
	int		i;
	int		set;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		print_error(1);
	stack = NULL;
	*width = ft_count_w(line, ' ');
	while (line != NULL)
	{
		i++;
		set = parsing_info(line, &stack, width, set_fd);
		if (set != 0)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	*height = i;
	free(line);
	close(fd);
	return (stack);
}
