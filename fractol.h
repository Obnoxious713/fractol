/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:24:14 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 12:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** ------ LIBRARIES ------
*/
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libgfx/minilibx/mlx.h"
# include "libft/libft.h"
# include "keys.h"

/*
** ------ TYPEDEFS ------
*/
typedef struct		s_fract
{
	long double		x;
	long double		y;
	long double		re;
	long double 	im;
}					t_fract;

typedef struct		s_view
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;
	int				*color;
	int				color_nbr;
	int				bpp;
	int				line_size;
	int				endian;
	int				max_iter;
	int				count[64];
	int				width;
	int				height;
	double			mouse_x;
	double			mouse_y;
	int				color_spin;
	int				zoom;
	double			x_shift;
	double			y_shift;
	char			mode;
	int				changed:1;
	int				trippy:1;
	int				fuzz:1;
	int				(*fract_func)(struct s_view*, double x, double y);
	t_fract			*fract;
	t_keys			*pressed;
}					t_view;

/*
** ------ FUNCTIONS ------
*/
void		usage(void);

int				mouse_release_hook(int button, int x, int y, t_view *view);
int				mouse_press_hook(int button, int x, int y, t_view *view);
int				motion_hook(int x, int y, t_view *view);

static void		toggle_pressed(int keycode, t_view *view, int toggle);
static void		toggle_ijkl(int keycode, t_view *view, int toggle);
static void		toggle_wasd(int keycode, t_view *view, int toggle);

void			use_image(t_view *view);
void			create_image(t_view *view);
void			put_pixel_to_img(t_view *view, int x, int y, int color);

int				loop_hook(t_view *view);
int				exit_hook(t_view *view);
int				expose_hook(t_view *view);
int				key_press_hook(int keycode, t_view *view);
int				key_release_hook(int keycode, t_view *view);

t_view			*create_view(void *mlx);
void			set_hooks(t_view *view);
void			init_view(t_view *view);
void			redraw(t_view *view);

void			hardset_color_table(t_view *view);
void			trip_color_table(t_view *view);
void			init_color_table(t_view *view, int color_nbr);


#endif
