/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:03:04 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:03:05 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int				motion_hook(int x, int y, t_view *view)
{
	if (!view->pressed->space)
	{
		view->mouse_x = x;
		view->mouse_y = y;
		view->changed = 1;
	}
	return (0);
}

int				mouse_press_hook(int button, int x, int y, t_view *view)
{
	if (button == 1)
		view->max_iter += 4;
	else if (button == 2)
		view->max_iter -= 8;
	if (button == 5)
	{
		x -= view->width / 2;
		y -= view->height / 2;
		view->zoom = (view->zoom + 1) * 1.1;
		view->x_shift += x / view->zoom / 1.5;
		view->y_shift += y / view->zoom / 1.5;
	}
	else if (button == 4)
	{
		if (view->zoom > 2)
			view->zoom = (view->zoom - 1) / 1.1;
		if (view->zoom < 4)
			view->zoom = 1;
	}
	view->changed = 1;
	return (0);
}

int				mouse_release_hook(int button, int x, int y, t_view *view)
{
	(void)view;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}
