/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:00:54 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 16:00:56 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int				mandelbrot(t_view *view, double real, double imagine)
{
	double		tmp;
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	real = ((4.0 * real / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	imagine = ((4.0 * y / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y <= 4 && i < view->max_iter)
	{
		tmp = x * x - y * y + real;
		y = 2 * x * y + imagine;
		x = tmp;
		i++;
	}
	return (i);
}

int				julia(t_view *view, double x, double y)
{
	int			i;
	long double	tmp;

	i = 0;
	x = ((4.0 * x / view->width - 2.0) / view->zoom)
			+ (view->x_shift / view->width);
	y = ((4.0 * y / view->height - 2.0) / view->zoom)
			+ (view->y_shift / view->height);
	while (x * x + y * y < 4.0 && i < view->max_iter)
	{
		tmp = x * x - y * y + view->fract->real;
		y = 2 * x * y + view->fract->imagine;
		x = tmp;
		i++;
	}
	return (i);
}

int				julia_mouse(t_view *view, double x, double y)
{
	view->fract->real = view->mouse_x * 4.0 / view->width - 2;
	view->fract->imagine = view->mouse_y * 4.0 / view->height - 2;
	return (julia(view, x, y));
}
