/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:20:31 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/23 11:20:33 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_lkl(t_lkl *stack, t_fdf *fdf)
{
	t_lkl	*root;
	t_lkl	*n_root;

	while (stack != NULL)
	{
		n_root = stack->next;
		free(stack->z);
		stack = n_root;
	}
	while (fdf->stack)
	{
		root = fdf->stack->next;
		free(fdf->stack);
		fdf->stack = root;
	}
}

void	init_trans_view(t_fdf *fdf)
{
	if (fdf->width >= 400)
		fdf->zoomer = 1;
	else if (fdf->width >= 300)
		fdf->zoomer = 5;
	else
		fdf->zoomer = 15;
	fdf->x_p = (WIDTH / 2) - (fdf->width / 2);
	fdf->y_p = (HEIGHT / 2) - (fdf->height / 2);
	fdf->off_x = (fdf->width / 2);
	fdf->off_y = (fdf->height / 2);
	fdf->trans = 1;
	fdf->relief = 1;
	fdf->rot = 0;
	fdf->angle = D_ANG;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->teta = 0;
}

void	init_graph(t_fdf *fdf, char *filename, int *set_fd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(1);
	ft_filename(filename);
	fdf->stack = read_file(fd, &fdf->width, &fdf->height, set_fd);
	if (*set_fd == -1)
		print_error(3);
	else if (*set_fd == -2)
		print_error(4);
	fdf->matrix = ft_matrix(fdf, fdf->stack);
	init_trans_view(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF BONUS!");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	int		set_fd;

	if (ac == 2)
	{
		set_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		init_graph(fdf, av[1], &set_fd);
		free_lkl(fdf->stack, fdf);
		draw_the_thing(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		mlx_hook(fdf->win_ptr, 17, 0L, close_win, fdf);
		mlx_hook(fdf->win_ptr, 2, 1L << 0, do_event, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		print_error(2);
	return (0);
}
