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

#include "fractol.h"
#include "libft/libft.h"

void		usage(void)
{
	ft_putendl("Usage:\n./fractol '#'");
	ft_putendl("1: Mandelbrot\n2: Julia\n3: Julia^3");
	exit(0);
}

int			main(int ac, char **av)
{
	void	*mlx;
	t_view	*view;

	if (ac == 2)
		usage();
	mlx = mlx_init();
	view = view_create(mlx);
	if (av[1][0] == '1' || av[1][0] == '2' || av[1][0] == '3')
		view->mode = av[1][0];
	else
		usage();
	create_image(view);
	view->win = mlx_new_window(mlx, view->width, view->height,
								"Fractol");
	set_hooks(view);
	mlx_loop_hook(mlx, loop_hook, view);
	mlx_loop(mlx);
}
