/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_profiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:32:05 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/02 17:32:06 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			initial_color(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 64, 477, 477, 477);
}

void			color1(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 64, 377, 7, 277);
}

void			color2(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 64, 42, 98, 130);
}

void			color3(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 64, 432, 221, 177);
}

void			color4(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 64, 69, 274, 42);
}
