/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:25:49 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:24:36 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_refresh(t_window *win)
{
	win->r++;
	if (win->r == 2)
	{
		win->coords->i = 100;
		win->coords->start.r = win->coords->reload.r;
		win->coords->start.im = -win->coords->reload.im;
	}
	win->coords->x_min = -2.5;
	win->coords->y_min = 2.5;
	win->coords->x_max = 2.5;
	win->coords->y_max = -2.5;
	win->coords->ecart_x = win->coords->x_max - win->coords->x_min;
	win->coords->ecart_y = win->coords->y_max - win->coords->y_min;
	win->coords->dir = (W_WIDTH >= W_HEIGHT) ? ((double)50 / (double)W_HEIGHT)
		: ((double)50 / (double)W_WIDTH);
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}
