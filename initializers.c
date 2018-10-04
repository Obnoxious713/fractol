/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:55:08 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 15:55:09 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void				init_color_table(t_view *view, int r, int g, int b)
{
	int				i;
	float			f;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	view->color = (int*)ft_memalloc(sizeof(int) * view->color_nbr);
	f = 0;
	i = -1;
	while (++i < view->color_nbr)
	{
		red = (cos(f) + 1) * r;
		green = (sin(f) + 1) * g;
		blue = (-cos(f) + 1) * b;
		view->color[i] = blue << 16 | green << 8 | red;
		f += M_PI / view->color_nbr;
	}
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
	view->color_nbr = 64;
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
