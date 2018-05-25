/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_direction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:24:24 by gperez            #+#    #+#             */
/*   Updated: 2018/05/08 16:54:45 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	init(t_window *win)
{
	win->coords->d = 'd';
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
	win->coords->x_start = 0;
	win->coords->y_start = 0;
	win->coords->x_end = W_WIDTH;
	win->coords->y_end = W_HEIGHT;
	win->coords->d = 0;
}

void		k_direction(int key, t_window *win)
{
	if (key == 0)
	{
		win->coords->x_min -= win->coords->dir;
		win->coords->x_max -= win->coords->dir;
		ft_move_image(win, 'r');
	}
	else if (key == 1)
	{
		win->coords->y_min -= win->coords->dir;
		win->coords->y_max -= win->coords->dir;
		ft_move_image(win, 'd');
	}
	else if (key == 2)
	{
		win->coords->x_min += win->coords->dir;
		win->coords->x_max += win->coords->dir;
		ft_move_image(win, 'l');
	}
	else
	{
		win->coords->y_min += win->coords->dir;
		win->coords->y_max += win->coords->dir;
		ft_move_image(win, 'u');
	}
	init(win);
}
