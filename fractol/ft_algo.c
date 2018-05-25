/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:47:10 by gperez            #+#    #+#             */
/*   Updated: 2018/04/21 15:19:45 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandel(t_window *win, t_complex inc, int i_max)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.r = win->coords->start.r;
	z.im = win->coords->start.im;
	i = 0;
	while (i < i_max && (ft_module(z) < 4))
	{
		tmp.r = z.r * z.r - z.im * z.im;
		tmp.im = 2 * z.r * z.im;
		z.r = tmp.r + inc.r;
		z.im = tmp.im + inc.im;
		i++;
	}
	return (i);
}

static int	ft_julia(t_window *win, t_complex inc, int i_max)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.r = inc.r;
	z.im = inc.im;
	i = 0;
	while (i < i_max && (ft_module(z) < 4))
	{
		tmp.r = z.r * z.r - z.im * z.im;
		tmp.im = 2 * z.r * z.im;
		z.r = tmp.r + win->coords->start.r;
		z.im = tmp.im + win->coords->start.im;
		i++;
	}
	return (i);
}

static int	ft_boat(t_window *win, t_complex inc, int i_max)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.r = win->coords->start.r;
	z.im = win->coords->start.im;
	i = 0;
	while (i < i_max && (ft_module(z) < 4))
	{
		tmp.r = z.r * z.r - z.im * z.im;
		tmp.im = 2 * z.r * z.im;
		z.r = fabs(tmp.r + inc.r);
		z.im = fabs(tmp.im + inc.im);
		i++;
	}
	return (i);
}

static int	ft_julia_boat(t_window *win, t_complex inc, int i_max)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	z.r = inc.r;
	z.im = inc.im;
	i = 0;
	while (i < i_max && (ft_module(z) < 4))
	{
		tmp.r = z.r * z.r - z.im * z.im;
		tmp.im = 2 * z.r * z.im;
		z.r = fabs(tmp.r + win->coords->start.r);
		z.im = fabs(tmp.im + win->coords->start.im);
		i++;
	}
	return (i);
}

int			ft_algo(t_window *win, t_complex inc, int i_max)
{
	if (ft_strcmp(win->fractal, "mandel") == 0)
		return (ft_mandel(win, inc, i_max));
	else if (ft_strcmp(win->fractal, "julia") == 0)
		return (ft_julia(win, inc, i_max));
	else if (ft_strcmp(win->fractal, "boat") == 0)
		return (ft_boat(win, inc, i_max));
	else if (ft_strcmp(win->fractal, "julia_boat") == 0)
		return (ft_julia_boat(win, inc, i_max));
	return (0);
}
