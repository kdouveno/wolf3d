/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:31:02 by gperez            #+#    #+#             */
/*   Updated: 2018/05/10 11:39:15 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			my_key(int key, t_window *win)
{
	if (key != 15)
		win->r = 0;
	if (key == 0 || key == 1 || key == 2 || key == 13)
		k_direction(key, win);
	else if (key == 8)
		k_lock(win);
	else if (key == 15)
		k_refresh(win);
	else if (key == 34)
		k_interface(win);
	else if (key == 35)
		k_color(win);
	else if (key == 53)
		k_escape(win);
	else if (key == 69 || key == 78)
		k_zoom(win, key);
	if (key == 116 || key == 121)
		k_iter(win, key);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		k_coords(win, key);
	return (0);
}
