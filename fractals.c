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
#include <stdio.h>

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
		new_x = pow(x * x + y * y, (n / 2)) * cos(n * atan2(y, x)) +
						view->fract->real;
		y = pow(x * x + y * y, (n / 2)) * sin(n * atan2(y, x)) +
					view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_3m2p1(t_view *view, double x, double y)
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
		new_x = (x * x * x - y * y * x - (2 * x * y * y) + view->fract->real) - (x * x - y * y + view->fract->real) + (x + view->fract->real) + view->fract->real;
		y = (2 * x * x * y - y * y * y + view->fract->imag) - (2 * x * y + view->fract->imag) + (y + view->fract->imag) + view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_4m3m2(t_view *view, double x, double y)
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
		new_x = (x * x * x * x + y * y * y * y - (6 * x * x * y * y) + view->fract->real) - (x * x * x - y * y * x - (2 * x * y * y) + view->fract->real) - (x * x - y * y + view->fract->real) + view->fract->real;
		y = ((4 * x * x * x * y) - (4 * x * y * y * y) + view->fract->imag) - (2 * x * x * y - y * y * y + view->fract->imag) - (2 * x * y + view->fract->imag) + view->fract->imag;
		x = new_x;
		i++;
	}
	return (i);
}

int				julia_4p3p2p1(t_view *view, double x, double y)
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
		new_x = ((x * x * x * x + y * y * y * y - (6 * x * x * y * y) + view->fract->real) + (x * x * x - y * y * x - (2 * x * y * y) + view->fract->real) + (x * x - y * y + view->fract->real) + (x + view->fract->real) + view->fract->real);
		y = (((4 * x * x * x * y) - (4 * x * y * y * y) + view->fract->imag) + (2 * x * x * y - y * y * y + view->fract->imag) + (2 * x * y + view->fract->imag) + (y + view->fract->imag) + view->fract->imag);
		x = new_x;
		i++;
	}
	return (i);
}
