/*  */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hc_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:02:30 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/03 16:02:32 by jfleisch         ###   ########.fr       */
/*                                                                            */
/*  */

#include "fractal.h"

int				julia_squared(t_view *view, double x, double y)
{
	int			i;
	long double	new_x;

	i = 0;
	x = ((4.0 * x / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	y = ((4.0 * y / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y < 4.0 && i < view->max_iter)
	{
		new_x = x * x - y * y + view->fract->real;
		y = 2 * x * y + view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_cubed(t_view *view, double x, double y)
{
	int			i;
	long double	new_x;

	i = 0;
	x = ((4.0 * x / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	y = ((4.0 * y / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y < 4.0 && i < view->max_iter)
	{
		new_x = x * x * x - y * y * x - (2 * x * y * y) + view->fract->real;
		y = 2 * x * x * y - y * y * y + view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_quad(t_view *view, double x, double y)
{
	int			i;
	long double	new_x;

	i = 0;
	x = ((4.0 * x / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	y = ((4.0 * y / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y < 4.0 && i < view->max_iter)
	{
		new_x = x * x * x * x + y * y * y * y - (6 * x * x * y * y) + view->fract->real;
		y = (4 * x * x * x * y) - (4 * x * y * y * y) + view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}
