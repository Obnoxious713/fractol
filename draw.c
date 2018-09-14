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
	int			imagine;

	imagine = 0;
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			imagine = view->fract_func(view, x, y);
			if (imagine < view->max_iter)
			{
				put_pixel_to_img(view, x, y, view->color[
					(imagine + view->color_spin) % 64]);
			}
		}
	}
}
