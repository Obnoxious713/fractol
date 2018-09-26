/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:14:32 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 16:14:33 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			show_fractal(t_view *view)
{
	int			x;
	int			y;
	int			i;

	i = 0;
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			i = view->fract_func(view, x, y);
			if (i < view->max_iter)
			{
				if (view->trippy)
					view->count[i % 122]++;
				put_pixel_to_img(view, x, y, view->color[
					((view->trippy ? view->count[i] : i) + view->color_inc) % 122]);
			}
		}
	}
}
