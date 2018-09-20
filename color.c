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

#include "fractol.h"
#include "libft/libft.h"

void			init_color_table(t_view *view, int color_nbr)
{
	int			i;
	float		f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	view->color = (int*)ft_memalloc(sizeof(int) * color_nbr);
	f = 0;
	i = -1;
	while (++i < color_nbr)
	{
		r = (cos(f) + 1) * 477;
		g = (sin(f) + 1) * 477;
		b = (-cos(f) + 1) * 477;
		view->color[i] = b << 16 | g << 8 | r;
		f += M_PI / color_nbr;
	}
	view->color_nbr = color_nbr;
}

void			set_to_black(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color = (int*)ft_memalloc(sizeof(int) * 122);
}

void			hardset_color_table(t_view *view)
{
	int			i;
	static int	color[] = {
		0xFF00DE, 0xF00BD2,0xE30BF0, 0xD116DC,
		0x7700BA, 0x800BA, 0x8A00BA, 0x9300BA,
		0xB300FF, 0xAF07F6, 0x960FCE, 0x8111B0,
		// 15 lines of colors arranged in a 4 x 4 pattern
		// red, pink, purple, blue, black
		0x000197, 0x000177, 0x0000157 ,0x000137,
		0x000137, 0x000117, 0x000097 ,0x000077,
		0x000057, 0x000037, 0x000017 ,0x000000
	};

	view->color = (int*)ft_memalloc(sizeof(int) * 122);
	i = -1;
	while (++i < 122)
		view->color[i] = color[i];
}
