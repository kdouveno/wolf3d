/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:34:57 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:23:16 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_color(t_window *win)
{
	free(win->coords->pal_color);
	win->coords->pal_color = ft_random_color(win);
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}
