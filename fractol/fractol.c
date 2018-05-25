/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:28:33 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:56:00 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static int	ft_window(t_window *win)
{
	if ((win->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((win->win_ptr = mlx_new_window(win->mlx_ptr, W_WIDTH, W_HEIGHT,
					"Fractol")) == NULL)
		return (0);
	if ((win->img_ptr = mlx_new_image(win->mlx_ptr, W_WIDTH, W_HEIGHT)) == NULL)
		return (0);
	win->img->img_s = (unsigned int*)mlx_get_data_addr(win->img_ptr,
		&win->img->bpp, &win->img->size_line, &win->img->endian);
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, my_key, win);
	mlx_hook(win->win_ptr, ButtonPress, ButtonPressMask, my_mouse, win);
	mlx_hook(win->win_ptr, MotionNotify, PointerMotionMask, my_motion_mouse,
		win);
	mlx_loop(win->mlx_ptr);
	return (1);
}*/

static void	init(t_window *win)
{
	win->coords->pal_color = ft_random_color(win);
	free(win->coords->pal_color);
	win->coords->pal_color = ft_random_color(win);
	win->coords->x_start = 0;
	win->coords->y_start = 0;
	win->coords->x_end = W_WIDTH;
	win->coords->y_end = W_HEIGHT;
	win->coords->i = 100;
	win->coords->dir = (W_WIDTH >= W_HEIGHT) ? ((double)50 / (double)W_HEIGHT)
		: ((double)50 / (double)W_WIDTH);
	win->coords->x_min = -2.5;
	win->coords->y_min = 2.5;
	win->coords->x_max = 2.5;
	win->coords->y_max = -2.5;
	win->coords->ecart_x = win->coords->x_max - win->coords->x_min;
	win->coords->ecart_y = win->coords->y_max - win->coords->y_min;
	win->c = 'n';
	win->r = 0;
	win->inter = 'y';
	win->coords->d = 0;
	win->coords->x_mouse = 0;
	win->coords->y_mouse = 0;
}

static void	fractal_type(t_window *win, char *fractal)
{
	if (ft_strcmp(fractal, "mandel") == 0 || ft_strcmp(fractal, "boat") == 0)
	{
		win->coords->reload.r = 0;
		win->coords->reload.im = 0;
	}
	else if (ft_strcmp(fractal, "julia") == 0)
	{
		win->coords->reload.r = (((double)487 * (double)2) /
				(double)W_WIDTH) - (double)1;
		win->coords->reload.im = (((double)-153 * (double)2) /
				(double)W_HEIGHT) + (double)1;
	}
	else
	{
		win->coords->reload.r = (((double)728 * (double)2) /
				(double)W_WIDTH) - (double)1;
		win->coords->reload.im = (((double)-583 * (double)2) /
				(double)W_HEIGHT) + (double)1;
	}
}

void		fractol(char *fractal)
{
	t_window	win;
	t_coord		coords;
	t_img		img;

	srand(time(NULL));
	win.img = &img;
	win.coords = &coords;
	win.fractal = fractal;
	init(&win);
	fractal_type(&win, fractal);
	coords.start.r = coords.reload.r;
	coords.start.im = -coords.reload.im;
	/*
	if (ft_window(&win) == 0)
		ft_putendl("Error window");*/
}
