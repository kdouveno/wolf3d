/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_iter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:53:37 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:24:32 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_iter(t_window *win, int key)
{
	if (key == 116)
		ft_iteration(win->coords, 5);
	else
		ft_iteration(win->coords, -5);
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}
