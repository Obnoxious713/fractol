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

#include "fractol.h"
#include "libft/libft.h"

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

static void		toggle_ijkl(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_I)
		view->pressed->i = toggle;
	if (keycode == KEY_J)
		view->pressed->j = toggle;
	if (keycode == KEY_K)
		view->pressed->k = toggle;
	if (keycode == KEY_L)
		view->pressed->l = toggle;
}

void			toggle_pressed(int keycode, t_view *view, int toggle)
{
	toggle_wasd(keycode, view, toggle);
	toggle_ijkl(keycode, view, toggle);
	/* if (keycode == KEY_X)
		view->pressed->x = toggle;
	if (keycode == KEY_Y)
		view->pressed->y = toggle;
	if (keycode == KEY_Z)
		view->pressed->z = toggle; */
	if (keycode == KEY_Q)
		view->pressed->q = toggle;
	if (keycode == KEY_E)
		view->pressed->e = toggle;
	/* if (keycode == KEY_O)
		view->pressed->o = toggle;
	if (keycode == KEY_P)
		view->pressed->p = toggle;
	if (keycode == KEY_PLUS)
		view->pressed->plus = toggle;
	if (keycode == KEY_MINUS)
		view->pressed->minus = toggle; */
}
