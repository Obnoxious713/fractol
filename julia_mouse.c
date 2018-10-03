/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:14:09 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/03 16:14:12 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				julia_squared_mouse(t_view *view, double x, double y)
{
	view->fract->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->imag = view->mouse_y * 4.0 / view->height - 2;
	return (julia_squared(view, x, y));
}

int				julia_cubed_mouse(t_view *view, double x, double y)
{
	view->fract->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->imag = view->mouse_y * 4.0 / view->height - 2;
	return (julia_cubed(view, x, y));
}

int				julia_quad_mouse(t_view *view, double x, double y)
{
	view->fract->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->imag = view->mouse_y * 4.0 / view->height - 2;
	return (julia_quad(view, x, y));
}
