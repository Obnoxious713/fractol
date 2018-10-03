/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:24:14 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 12:24:15 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define THREAD_NUM 16

# include <pthread.h>
# include "keys.h"
# include "colors.h"
# include "libgfx/libgfx.h"
# include "libgfx/minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/complex/libftcomplex.h"

typedef struct		s_fract
{
	long double		x;
	long double		y;
	long double		real;
	long double		imag;
	// t_complex		*complex;
}					t_fract;

typedef struct		s_view
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;
	int				*color;
	int				color_nbr; // number of iterations
	int				bpp;
	int				line_size;
	int				endian;
	int				max_iter;
	int				count[64];
	int				width;
	int				height;
	double			mouse_x;
	double			mouse_y;
	int				color_inc;
	int				zoom;
	double			x_shift;
	double			y_shift;
	double			mu;
	double			mod;
	double			er;
	char			mode;
	int				changed:1;
	int				(*fract_func)(struct s_view*, double x, double y);
	t_fract			*fract;
	t_keys			*pressed;
}					t_view;

typedef struct	s_thread
{
	t_view		*view;
	int			count;
	int			id;
}				t_thread;

/*
** ------ FUNCTIONS ------
*/
void			usage(void);

int				mouse_release_hook(int button, int x, int y, t_view *view);
int				mouse_press_hook(int button, int x, int y, t_view *view);
int				motion_hook(int x, int y, t_view *view);

void			toggle_pressed(int keycode, t_view *view, int toggle);

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

void			initial_color(t_view *view);
void			color1(t_view *view);
void			color2(t_view *view);
void			color3(t_view *view);
void			color4(t_view *view);
void			init_color_table(t_view *view, int color_nbr, int r, int g, int b);

int				mandelbrot(t_view *view, double real, double imag);
int				julia(t_view *view, double x, double y);
int				julia_mouse(t_view *view, double x, double y);
int				julia_multi(t_view *view, double x, double y, int n);
int				julia_mouse_multi(t_view *view, double x, double y);

void			fract_thread(void *thread_arg);
pthread_t		make_thread(t_view *view, int index, int count);
void			thread_fractal(t_view *view);

#endif
