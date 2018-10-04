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
	init_color_table(view, 464, 464, 464);
}

void			color1(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 164, 0, 564);
}

void			color2(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 32, 164, 216);
}

void			color3(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 77, 377, 77);
}

void			color4(t_view *view)
{
	if (view->color)
		free(view->color);
	init_color_table(view, 264, 264, 64);
}
