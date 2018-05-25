/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motion_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:02:01 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:22:59 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_motion_mouse(int x, int y, t_window *win)
{
	win->coords->x_mouse = x;
	win->coords->y_mouse = y;
	if (y >= 0 && y < W_HEIGHT && x >= 0 && x < W_WIDTH)
	{
		if (win->c == 'y')
		{
			win->coords->x_start = 0;
			win->coords->y_start = 0;
			win->coords->x_end = W_WIDTH;
			win->coords->y_end = W_HEIGHT;
			win->coords->start.r = (((double)x * (double)2) /
					(double)W_WIDTH) - (double)1;
			win->coords->start.im = (((double)y * (double)2) /
					(double)W_HEIGHT) - (double)1;
			ft_draw(win);
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
					win->img_ptr, 0, 0);
			ft_interface(win, WHITE);
		}
	}
	return (0);
}
