/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_coords.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:58:01 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:23:37 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_coords(t_window *win, int key)
{
	if (key == 123)
		win->coords->start.r -= 0.01;
	else if (key == 124)
		win->coords->start.r += 0.01;
	else if (key == 125)
		win->coords->start.im -= 0.01;
	else
		win->coords->start.im += 0.01;
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}
