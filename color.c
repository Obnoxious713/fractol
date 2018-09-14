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
		r = (cos(f) + 1) * 127;
		g = (sin(f) + 1) * 127;
		b = (-cos(f) + 1) * 127;
		view->color[i] = b << 16 | g << 8 | r;
		f += M_PI / color_nbr;
	}
	view->color_nbr = color_nbr;
}

void			trip_color_table(t_view *view)
{
	if (view->color)
		free(view->color);
	view->color = (int*)ft_memalloc(sizeof(int) * 64);
}

void			hardset_color_table(t_view *view)
{
	int			i;
	static int	color[] = {
		0x0048EF, 0x0057F0, 0x0166f0, 0x0274F0,
		0x0383F0, 0x0491F0, 0x05A0F1, 0x06AEF1,
		0x07BCF1, 0x08CAF1, 0x08D8f1, 0x09E6F2,
		0x0AF2F0, 0x0BF2E3, 0x0CF2D5, 0x0DF2C8,
		0x0EF3BB, 0x0FF3AE, 0x10F3A1, 0x11F394,
		0x12F388, 0x13F47B, 0x13F46E, 0x14F462,
		0x15F455, 0x16F449, 0x17F43D, 0x18F531,
		0x19F525, 0x1BF51A, 0x29F51B, 0x37F51C,
		0x44F61D, 0x52F61E, 0x5FF61F, 0x6CF620,
		0x79F621, 0x87F721, 0x94F722, 0xA1F723,
		0xADF724, 0xBAF725, 0xC7F826, 0xD4F827,
		0xE0F828, 0xECF829, 0xF8F82A, 0xF8EC2B,
		0xF9E02C, 0xF9D42D, 0xF9C92E, 0xF9BD2F,
		0xF9B230, 0xfAA731, 0xFA9B32, 0xFA9033,
		0xFA8534, 0xFA7A35, 0xFB6F36, 0xFB6537,
		0xFB5A38, 0xFB4F39, 0xFB453A, 0xFC3A3A
	};

	view->color = (int*)ft_memalloc(sizeof(int) * 64);
	i = -1;
	while (++i < 64)
		view->color[i] = color[i];
}
