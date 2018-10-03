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

#include "fractal.h"
#include "libft/libft.h"

void			initial_color(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color_nbr = 64;
	init_color_table(view, 477, 477, 477);
}

void			color1(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color_nbr = 64;
	init_color_table(view, 377, 7, 277);
}

void			color2(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color_nbr = 64;
	init_color_table(view, 42, 98, 130);
}

void			color3(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color_nbr = 64;
	init_color_table(view, 432, 221, 177);
}

void			color4(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color_nbr = 64;
	init_color_table(view, 69, 274, 42);
}
