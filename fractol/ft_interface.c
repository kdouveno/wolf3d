/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:04:35 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:24:21 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	part_2(t_window *win, int color, int start, int space)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 9, color, "Page up :    + iter");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 10, color, "Page down :  - iter");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 11, color, "Color :      p");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 12, color, "Interface :  i");
}

static void	caption(t_window *win, int color)
{
	int	start;
	int	space;

	start = 50;
	space = 20;
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space, color, "Escape :     ESC");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 2, color, "Direction :  w a s d");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 3, color, "Refresh :    r");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 4, color, "Restart  :   r (2 times)");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 5, color, "Zoom :       + -");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 6, color, "Mouse Scale: c");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 7, color, "Scaling r :  left right");
	mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 16,
			start + space * 8, color, "Scaling im : up down");
	part_2(win, color, start, space);
}

void		ft_interface(t_window *win, int color)
{
	if (win->inter == 'y')
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, W_WIDTH / 2 - 40,
				20, WHITE, win->fractal);
		if (W_WIDTH >= 650)
			caption(win, color);
	}
}
