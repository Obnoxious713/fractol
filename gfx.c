/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:42:19 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:42:19 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			redraw(t_view *view)
{
	view->changed = 0;
	if (view->mode == '1')
		view->fract_func = mandelbrot;
	else if (view->mode == '2')
		view->fract_func = julia_mouse;
	// else
	// 	view->fract_func = newton_mouse;
	thread_fractal(view);
	use_image(view);
}

void			init_view(t_view *view)
{
	view->changed = 1;
	view->max_iter = 128;
	view->width = 1200;
	view->height = 1200;
	view->mouse_x = 0;
	view->mouse_y = 0;
	view->color_inc = 0;
	view->zoom = 1.0;
	view->x_shift = 0;
	view->y_shift = 0;
}

void			set_hooks(t_view *view)
{
	mlx_do_key_autorepeatoff(view->mlx);
	mlx_hook(view->win, 2, 0, key_press_hook, view);
	mlx_hook(view->win, 3, 0, key_release_hook, view);
	mlx_hook(view->win, 4, 0, mouse_press_hook, view);
	mlx_hook(view->win, 5, 0, mouse_release_hook, view);
	mlx_hook(view->win, 6, 0, motion_hook, view);
	mlx_hook(view->win, 12, 0, expose_hook, view);
	mlx_hook(view->win, 17, 0, exit_hook, view);
}

t_view			*create_view(void *mlx)
{
	t_view		*view;

	view = (t_view*)ft_memalloc(sizeof(t_view));
	view->pressed = (t_keys*)ft_memalloc(sizeof(t_keys));
	view->fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	view->fract->complex = (t_complex*)ft_memalloc(sizeof(t_complex));
	init_view(view);
	view->pressed->space = 0;
	view->pressed->w = 0;
	view->pressed->a = 0;
	view->pressed->s = 0;
	view->pressed->d = 0;
	view->pressed->i = 0;
	view->pressed->k = 0;
	view->pressed->q = 0;
	view->pressed->z = 0;
	view->pressed->e = 0;
	initial_color(view);
	view->mlx = mlx;
	return (view);
}
