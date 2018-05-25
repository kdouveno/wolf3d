/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_zoom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:42:25 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:25:10 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom(t_window *win, int key)
{
	if (key == 69 || key == 5)
	{
		win->coords->ecart_x /= 4;
		win->coords->ecart_y /= 4;
		win->coords->x_min += win->coords->ecart_x;
		win->coords->x_max -= win->coords->ecart_x;
		win->coords->y_min += win->coords->ecart_y;
		win->coords->y_max -= win->coords->ecart_y;
		win->coords->dir /= 2;
	}
	else
	{
		win->coords->ecart_x /= 2;
		win->coords->ecart_y /= 2;
		win->coords->x_min -= win->coords->ecart_x;
		win->coords->x_max += win->coords->ecart_x;
		win->coords->y_min -= win->coords->ecart_y;
		win->coords->y_max += win->coords->ecart_y;
		win->coords->dir *= 2;
	}
}

static void	mouse_center(t_window *win, double x_n, double y_n)
{
	x_n = win->coords->x_mouse * win->coords->ecart_x
		/ W_WIDTH + win->coords->x_min;
	y_n = win->coords->y_mouse * win->coords->ecart_y
		/ W_HEIGHT + win->coords->y_min;
	win->coords->x_min = x_n - win->coords->ecart_x / 2;
	win->coords->y_min = y_n - win->coords->ecart_y / 2;
	win->coords->x_max = x_n + win->coords->ecart_x / 2;
	win->coords->y_max = y_n + win->coords->ecart_y / 2;
}

static void	init(t_window *win)
{
	win->coords->ecart_x = win->coords->x_max - win->coords->x_min;
	win->coords->ecart_y = win->coords->y_max - win->coords->y_min;
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}

void		k_zoom(t_window *win, int key)
{
	double	x_n;
	double	y_n;

	x_n = 0;
	y_n = 0;
	if (win->coords->x_mouse >= 0 && win->coords->x_mouse < W_WIDTH
			&& win->coords->y_mouse >= 0 && win->coords->x_mouse < W_WIDTH)
		mouse_center(win, x_n, y_n);
	zoom(win, key);
	init(win);
}
