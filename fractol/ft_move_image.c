/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:48:30 by gperez            #+#    #+#             */
/*   Updated: 2018/05/06 16:41:41 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_move_image_l(t_window *win, int value)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < W_HEIGHT)
	{
		while (x + value < W_WIDTH)
		{
			win->img->img_s[y * W_WIDTH + x] =
				win->img->img_s[y * W_WIDTH + x + value];
			x += 1;
		}
		x = 0;
		y += 1;
	}
	win->coords->x_start = W_WIDTH - value;
	win->coords->y_start = 0;
	win->coords->x_end = W_WIDTH;
	win->coords->y_end = W_HEIGHT;
}

void		ft_move_image_r(t_window *win, int value)
{
	int		x;
	int		y;

	x = W_WIDTH - 1;
	y = W_HEIGHT - 1;
	while (y >= 0)
	{
		while (x - value >= 0)
		{
			win->img->img_s[y * W_WIDTH + x] =
				win->img->img_s[y * W_WIDTH + x - value];
			x--;
		}
		x = W_WIDTH - 1;
		y--;
	}
	win->coords->x_start = 0;
	win->coords->y_start = 0;
	win->coords->x_end = value;
	win->coords->y_end = W_HEIGHT;
}

void		ft_move_image_u(t_window *win, int value)
{
	int		x;
	int		y;

	x = W_WIDTH;
	y = W_HEIGHT;
	while (y - value >= 0)
	{
		while (x >= 0)
		{
			win->img->img_s[y * W_WIDTH + x] =
				win->img->img_s[(y - value) * W_WIDTH + x];
			x--;
		}
		x = W_WIDTH - 1;
		y--;
	}
	win->coords->x_start = 0;
	win->coords->y_start = 0;
	win->coords->x_end = W_WIDTH;
	win->coords->y_end = value;
}

void		ft_move_image_d(t_window *win, int value)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y + value < W_HEIGHT)
	{
		while (x < W_WIDTH)
		{
			win->img->img_s[y * W_WIDTH + x] =
				win->img->img_s[(y + value) * W_WIDTH + x];
			x += 1;
		}
		x = 0;
		y += 1;
	}
	win->coords->x_start = 0;
	win->coords->y_start = W_HEIGHT - value;
	win->coords->x_end = W_WIDTH;
	win->coords->y_end = W_HEIGHT;
}

void		ft_move_image(t_window *win, char d)
{
	int value;

	value = round((double)W_WIDTH * win->coords->dir /
		(win->coords->x_max - win->coords->x_min));
	if (d == 'l')
		ft_move_image_l(win, value);
	else if (d == 'r')
		ft_move_image_r(win, value);
	else if (d == 'u')
		ft_move_image_u(win, value);
	else
		ft_move_image_d(win, value);
}
