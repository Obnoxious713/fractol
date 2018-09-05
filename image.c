/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:21:26 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:21:26 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			put_pixel_to_img(t_view *view, int x, int y, int color)
{
	int			i;

	if (x > 0 && y > 0 && x < view->width && y < view->height)
	{
		i = (x * (view->bpp / 8)) + (y * view->line_size);
		view->pixel[i] = color;
		view->pixel[++i] = color >> 8;
		view->pixel[++i] = color >> 16;
	}
}

void			create_image(t_view *view)
{
	view->img = mlx_new_image(view->mlx, view->width, view->height);
	view->pixel = mlx_get_data_addr(view->img, &(view->bpp), &(view->line_size), &(view->endian));
}

void			use_image(t_view *view)
{
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
	create_image(view);
}
