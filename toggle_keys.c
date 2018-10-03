/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:09:55 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:09:56 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void		toggle_nums(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_NUM_PLUS)
		view->pressed->num_plus = toggle;
	if (keycode == KEY_NUM_MINUS)
		view->pressed->num_minus = toggle;
	if (keycode == KEY_ONE)
		view->pressed->one = toggle;
	if (keycode == KEY_TWO)
		view->pressed->two = toggle;
	if (keycode == KEY_THREE)
		view->pressed->three = toggle;
	if (keycode == KEY_FOUR)
		view->pressed->four = toggle;
	if (keycode == KEY_FIVE)
		view->pressed->five = toggle;
}

static void		toggle_wasd(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_W)
		view->pressed->w = toggle;
	if (keycode == KEY_A)
		view->pressed->a = toggle;
	if (keycode == KEY_S)
		view->pressed->s = toggle;
	if (keycode == KEY_D)
		view->pressed->d = toggle;
}

static void		toggle_arrows(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_UP)
		view->pressed->up = toggle;
	if (keycode == KEY_LEFT)
		view->pressed->left = toggle;
	if (keycode == KEY_DOWN)
		view->pressed->down = toggle;
	if (keycode == KEY_RIGHT)
		view->pressed->right = toggle;
}

void			key_pressed(t_view *view)
{
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
}

void			toggle_pressed(int keycode, t_view *view, int toggle)
{
	toggle_wasd(keycode, view, toggle);
	toggle_arrows(keycode, view, toggle);
	toggle_nums(keycode, view, toggle);
	if (keycode == KEY_X)
		view->pressed->x = toggle;
	if (keycode == KEY_Y)
		view->pressed->y = toggle;
	if (keycode == KEY_I)
		view->pressed->i = toggle;
	if (keycode == KEY_O)
		view->pressed->o = toggle;
}
