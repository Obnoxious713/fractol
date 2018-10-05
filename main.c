/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:52:46 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 12:52:47 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		usage(void)
{
	ft_putendl("Usage:\n./fractal '#'");
	ft_putendl("1: Mandelbrot\n2: Julia");
	ft_putendl("3: Julia Cube\n4: Julia Quad\n5: Julia Quin");
	ft_putendl("6: Julia Sext\n7: Julia Sept\n8: Julia Oct\n:9 Julia Non");
	exit(0);
}

int			main(int ac, char **av)
{
	void	*mlx;
	t_view	*view;

	if (ac != 2)
		usage();
	mlx = mlx_init();
	view = create_view(mlx);
	if (av[1][0] >= '1' && av[1][0] <= '9')
		view->mode = av[1][0];
	else
		usage();
	create_image(view);
	view->win = mlx_new_window(mlx, view->width, view->height, "fractol");
	set_hooks(view);
	mlx_loop_hook(mlx, loop_hook, view);
	mlx_loop(mlx);
}
