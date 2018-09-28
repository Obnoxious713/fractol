/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:14:32 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 16:14:33 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void			fract_thread(void *thread_arg)
{
	int			i;
	int			x;
	int			y;
	t_view		*view;
	t_thread	*thread;

	i = 0;
	thread = (t_thread*)thread_arg;
	view = thread->view;
	y = (view->height / thread->count * (thread->id - 1)) - 1;
	while (++y < view->height / thread->count * thread->id)
	{
		x = -1;
		while (++x < view->width)
		{
			i = view->fract_func(view, x, y);
			if (i < view->max_iter)
			{
				put_pixel_to_img(view, x, y, view->color[
					(i + view->color_inc) % 128]);
			}
		}
	}
}

pthread_t		make_thread(t_view *view, int index, int count)
{
	pthread_t	thread_id;
	t_thread	*thread;

	thread = (t_thread*)ft_memalloc(sizeof(t_thread));
	thread->count = count;
	thread->id = index;
	thread->view = view;
	pthread_create(&thread_id, NULL, (void*)fract_thread, thread);
	return (thread_id);
}

void			thread_fractal(t_view *view)
{
	int			i;
	int			tnum;
	pthread_t	threads[THREAD_NUM];

	i = 0;
	tnum = THREAD_NUM;
	while (++i < tnum + 1)
		threads[i - 1] = make_thread(view, i, tnum);
	i = -1;
	while (++i < tnum)
		pthread_join(threads[i], NULL);
}
