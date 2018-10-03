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
