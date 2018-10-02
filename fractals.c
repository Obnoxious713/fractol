/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:00:54 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 16:00:56 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				mandelbrot(t_view *view, double real, double imag)
{
	int			i;
	double		x;
	double		y;
	double		new_x;

	i = 0;
	x = 0;
	y = 0;
	real = ((4.0 * real / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	imag = ((4.0 * imag / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y <= 4 && i < view->max_iter)
	{
		new_x = x * x - y * y + real;
		y = 2 * x * y + imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia(t_view *view, double x, double y)
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
		new_x = x * x - y * y + view->fract->complex->real;
		y = 2 * x * y + view->fract->complex->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_mouse(t_view *view, double x, double y)
{
	view->fract->complex->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->complex->imag = view->mouse_y * 4.0 / view->height - 2;
	return (julia(view, x, y));
}

int				julia_multi(t_view *view, double x, double y, int n)
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
		new_x = pow(x * x + y * y, (n / 2)) * cos(n * atan2(y, x)) + view->fract->complex->real;
		y = pow(x * x + y * y, (n / 2)) * sin(n * atan2(y, x)) + view->fract->complex->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_mouse_multi(t_view *view, double x, double y)
{
	view->fract->complex->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->complex->imag = view->mouse_y * 4.0 / view->height - 2;
	return (julia_multi(view, x, y, ft_atoi(&view->mode)));
}
