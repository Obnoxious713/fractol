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
	ft_putendl("1: Mandelbrot\n2: Julia z^2 + c");
	ft_putendl("3: Julia z^3 + c\n4: Julia z^4 + c\n5: Julia z^5 + c");
	ft_putendl("6: Julia z^6 + c\n7: Julia z^3 - z^2 + z + c");
	ft_putendl("8: Julia z^8 + c\n:9 Julia z^4 - z^3 - z^2 + c");
	ft_putendl("0: Julia sqrt(z^4 + z^3 + z^2 + z + c)");
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
	if (av[1][0] >= '0' && av[1][0] <= '9')
		view->mode = av[1][0];
	else
		usage();
	create_image(view);
	view->win = mlx_new_window(mlx, view->width, view->height, "fractol");
	set_hooks(view);
	mlx_loop_hook(mlx, loop_hook, view);
	mlx_loop(mlx);
}
