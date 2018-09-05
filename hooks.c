/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:29:52 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:29:53 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int				key_release_hook(int keycode, t_view *view)
{
	toggle_pressed(keycode, view, 0);
	view->changed = 1;
	return (0);
}

int				key_press_hook(int keycode, t_view *view)
{
	if (keycode == KEY_SPACE)
		view->pressed->space = !view->pressed->space;
	if (keycode == KEY_E)
		view->trippy = !view->trippy;
	if (keycode == KEY_ESC)
		exit(0);
	toggle_pressed(keycode, view, 1);
	view->changed = 1;
	return (0);
}

int				expose_hook(t_view *view)
{
	if (view->changed)
		redraw(view);
	return (0);
}

int				exit_hook(t_view *view)
{
	mlx_destroy_window(view->mlx, view->win);
	exit(0);
	return (0);
}

int				loop_hook(t_view *view)
{
	if (view->pressed->a || view->pressed->s || view->pressed->w ||
		view->pressed->d || view->pressed->i || view->pressed->k ||
		view->pressed->q)
		view->changed = 1;
	if (view->pressed->a)
		view->x_shift += 10;
	else if (view->pressed->d)
		view->x_shift -= 10;
	if (view->pressed->w)
		view->y_shift += 10;
	else if (view->pressed->s)
		view->y_shift -= 10;
	if (view->pressed->i)
		view->zoom = (view->zoom + 1) * 1.1;
	else if (view->pressed->k && view->zoom > 1)
		view->zoom = (view->zoom - 1) * 1.1;
	else if (view->pressed->q)
		view->color_spin++;
	if (view->changed)
		redraw(view);
	return (0);
}
