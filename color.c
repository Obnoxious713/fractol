/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:54:07 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:54:08 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			init_color_table(t_view *view, int color_nbr, int r, int g, int b)
{
	int			i;
	float		f;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	view->color = (int*)ft_memalloc(sizeof(int) * color_nbr);
	f = 0;
	i = -1;
	while (++i < color_nbr)
	{
		red = (cos(f) + 1) * r;
		green = (sin(f) + 1) * g;
		blue = (-cos(f) + 1) * b;
		view->color[i] = blue << 16 | green << 8 | red;
		f += M_PI / color_nbr;
	}
	view->color_nbr = color_nbr;
}

void			initial_color(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 128, 477, 477, 477);
}

void			color1(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 128, 377, 7, 277);
}

void			color2(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 128, 42, 98, 130);
}

void			color3(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 128, 432, 221, 177);
}

void			color4(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 128, 69, 274, 42);
}
