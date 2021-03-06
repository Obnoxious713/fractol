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

/*
**void			hardset_color_table(t_view *view)
**{
**	int			i;
**	static int	color[] = {
**		0xFF00DE, 0xF00BD2,0xE30BF0, 0xD116DC,
**		0x7700BA, 0x800BA, 0x8A00BA, 0x9300BA,
**		0xB300FF, 0xAF07F6, 0x960FCE, 0x8111B0,
**		// 15 lines of colors arranged in a 4 x 4 pattern
**		// red, pink, purple, blue, black
**		0x000197, 0x000177, 0x0000157 ,0x000137,
**		0x000137, 0x000117, 0x000097 ,0x000077,
**		0x000057, 0x000037, 0x000017 ,0x000000
**	};
**
**	view->color = (int*)ft_memalloc(sizeof(int) * 64);
**	i = -1;
**	while (++i < 64)
**		view->color[i] = color[i];
**}
**
**void			hardset_delek(t_view *view)
**{
**	int			i;
**	static int	color[] = {
**		DRK_RED, DRK_RED + 25, DRK_RED + 50, DRK_RED + 75,
**		DRK_RED + 77, DRK_RED + 154, DRK_RED + 231,
**		DRK_MAGENTA, DRK_MAGENTA + 25, DRK_MAGENTA + 50, DRK_MAGENTA + 75,
**		DRK_MAGENTA + 77, DRK_MAGENTA + 154, DRK_MAGENTA + 231,
**		DEEP_PINK, DEEP_PINK + 25, DEEP_PINK + 50, DEEP_PINK + 75,
**		DEEP_PINK + 77, DEEP_PINK + 154, DEEP_PINK + 231,
**		DRK_GREEN, DRK_GREEN + 25, DRK_GREEN + 50, DRK_GREEN + 75,
**		DRK_GREEN + 77, DRK_GREEN + 154, DRK_GREEN + 231,
**		DRK_CYAN, DRK_CYAN + 25, DRK_CYAN + 50, DRK_CYAN + 75,
**		DRK_CYAN + 77, DRK_CYAN + 154, DRK_CYAN + 231,
**		COBALT, DRK_CYAN + 25, DRK_CYAN + 50, DRK_CYAN + 75,
**		COBALT + 77, COBALT + 154, COBALT + 231,
**	};
**
**	view->color = (int*)ft_memalloc(sizeof(int) * 64);
**	i = -1;
**	while (++i < 64)
**		view->color[i] = color[i];
**}
*/
