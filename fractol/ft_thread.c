/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:19:09 by gperez            #+#    #+#             */
/*   Updated: 2018/05/08 17:02:58 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_translate(t_arg *arg, t_window *win)
{
	t_complex	inc;

	inc.r = arg->x * win->coords->ecart_x / W_WIDTH
		+ win->coords->x_min;
	inc.im = -arg->y * win->coords->ecart_y / W_HEIGHT
		- win->coords->y_min;
	return (ft_algo(win, inc, win->coords->i));
}

void		*thread(void *arg)
{
	t_arg *a;

	a = arg;
	while (a->y < a->y_end)
	{
		while (a->x < a->x_end)
		{
			if ((a->i = ft_translate(a, a->win)) < a->win->coords->i)
			{
				while (a->i % a->cmpt != 0)
					a->cmpt--;
				a->win->img->img_s[a->y * W_WIDTH +
					a->x] = a->win->coords->pal_color[a->cmpt - 1];
				a->cmpt = a->win->coords->nbr_color;
			}
			else
				a->win->img->img_s[a->y * W_WIDTH + a->x] = 0;
			a->x++;
		}
		a->x = a->x_start;
		a->y++;
	}
	pthread_exit(NULL);
}
