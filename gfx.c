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

#include "fractal.h"

void			redraw(t_view *view)
{
	view->changed = 0;
	if (view->mode == '1')
		view->fract_func = mandelbrot;
	else if (view->mode == '2')
		view->fract_func = julia_squared_mouse;
	else if (view->mode == '3')
		view->fract_func = julia_cubed_mouse;
	// else if (view->mode == '4')
	// 	view->fract_func = julia_quad_mouse;
	else
		view->fract_func = julia_mouse_multi;
	thread_fractal(view);
	use_image(view);
}

void			init_view(t_view *view)
{
	view->changed = 1;
	view->max_iter = 64;
	view->width = 1400;
	view->height = 1400;
	view->mouse_x = 0;
	view->mouse_y = 0;
	view->color_inc = 0;
	view->zoom = 1.0;
	view->x_shift = 0;
	view->y_shift = 0;
}

void			init_pressed(t_view *view)
{
	view->pressed->space = 0;
	view->pressed->w = 0;
	view->pressed->a = 0;
	view->pressed->s = 0;
	view->pressed->d = 0;
	view->pressed->i = 0;
	view->pressed->o = 0;
	view->pressed->num_plus = 0;
	view->pressed->num_minus = 0;
	view->pressed->one = 0;
	view->pressed->two = 0;
	view->pressed->three = 0;
	view->pressed->four = 0;
	view->pressed->five = 0;
	view->pressed->up = 0;
	view->pressed->down = 0;
	view->pressed->left = 0;
	view->pressed->right = 0;
}

void			set_hooks(t_view *view)
{
	mlx_do_key_autorepeatoff(view->mlx);
	mlx_hook(view->win, 2, 0, key_press_hook, view);
	mlx_hook(view->win, 3, 0, key_release_hook, view);
	mlx_hook(view->win, 4, 0, mouse_press_hook, view);
	mlx_hook(view->win, 5, 0, mouse_release_hook, view);
	mlx_hook(view->win, 6, 0, motion_hook, view);
	mlx_hook(view->win, 7, 0, expose_hook, view);
	mlx_hook(view->win, 8, 0, exit_hook, view);
}

t_view			*create_view(void *mlx)
{
	t_view		*view;

	view = (t_view*)ft_memalloc(sizeof(t_view));
	view->pressed = (t_keys*)ft_memalloc(sizeof(t_keys));
	view->fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	init_view(view);
	init_pressed(view);
	initial_color(view);
	view->mlx = mlx;
	return (view);
}
