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

#include "fractal.h"
#include "libft/libft.h"

int				key_release_hook(int keycode, t_view *view)
{
	toggle_pressed(keycode, view, 0);
	view->changed = 1;
	return (0);
}

int				key_press_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ONE)
		initial_color(view);
	else if (keycode == KEY_TWO)
		color1(view);
	else if (keycode == KEY_THREE)
		color2(view);
	else if (keycode == KEY_FOUR)
		color3(view);
	else if (keycode == KEY_FIVE)
		color4(view);
	if (keycode == KEY_SPACE)
		view->pressed->space = !view->pressed->space;
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
		view->pressed->d || view->pressed->q || view->pressed->z ||
		view->pressed->i || view->pressed->o || view->pressed->num_minus ||
		view->pressed->num_plus || view->pressed->left ||
		view->pressed->right || view->pressed->up || view->pressed->down)
		view->changed = 1;
	if (view->pressed->a)
		view->x_shift -= 1;
	else if (view->pressed->d)
		view->x_shift += 1;
	if (view->pressed->w)
		view->y_shift -= 1;
	else if (view->pressed->s)
		view->y_shift += 1;
	if (view->pressed->left)
		view->x_shift -= 10;
	else if (view->pressed->right)
		view->x_shift += 10;
	if (view->pressed->up)
		view->y_shift -= 10;
	else if (view->pressed->down)
		view->y_shift += 10;
	if (view->pressed->i)
		view->zoom = (view->zoom + 1) * 1.1;
	else if (view->pressed->o && view->zoom > 1)
		view->zoom = (view->zoom - 1) * 1.1;
	if (view->pressed->num_plus)
		view->color_inc++;
	else if (view->pressed->num_minus)
		view->color_inc--;
	if (view->changed)
		redraw(view);
	return (0);
}
