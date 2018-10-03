/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:55:08 by jfleisch          #+#    #+#             */
/*   Updated: 2018/07/21 15:55:09 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libgfx.h"
#include "../fractal.h"

void				init_color_table(t_view *view, int r, int g, int b)
{
	int				i;
	float			f;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	view->color = (int*)ft_memalloc(sizeof(int) * view->color_nbr);
	f = 0;
	i = -1;
	while (++i < view->color_nbr)
	{
		red = (cos(f) + 1) * r;
		green = (sin(f) + 1) * g;
		blue = (-cos(f) + 1) * b;
		view->color[i] = blue << 16 | green << 8 | red;
		f += M_PI / view->color_nbr;
	}
}
