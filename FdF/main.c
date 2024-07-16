/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:09 by irabesan          #+#    #+#             */
/*   Updated: 2024/07/16 13:21:10 by irabesan         ###   ########.fr       */
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
		fdf->zoomer = 20;
	fdf->x_p = (WIDTH / 2) - (fdf->width / 2);
	fdf->y_p = (HEIGHT / 2) - (fdf->height / 2);
	fdf->trans = 1;
	fdf->angle = ANG;
	fdf->relief = 1;
	
}

void	init_graph(t_fdf *fdf, char *file_fdf, int *check_fd)
{
	t_lkl	*stack;
	int	fd;

	fd = open(file_fdf, O_RDONLY);
	if (fd < 0)
		print_error(1);
	ft_filename(file_fdf);
	fdf->stack = read_file(fd, &fdf->width, &fdf->height, check_fd);
	if (*check_fd == -1)
		print_error(3);
	if (*check_fd == -2)
		print_error(4);
	stack = fdf->stack;
	fdf->matrix = ft_matrix(fdf, stack);
	free_lkl(fdf->stack, fdf);
	fdf->stack = NULL;
	init_trans_view(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "rendu FdF!"); 
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_fdf *fdf;
	int	set_fd;

	if (ac == 2)
	{
		set_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		init_graph(fdf, av[1], &set_fd);
		free(fdf->stack);
		draw_the_thing(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0 , 0);
		mlx_key_hook(fdf->win_ptr, key_press, fdf);
		mlx_loop(fdf->mlx_ptr);
		
	}
}
