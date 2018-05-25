/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_interface.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:32:23 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:24:29 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_interface(t_window *win)
{
	if (win->inter == 'y')
		win->inter = 'n';
	else
		win->inter = 'y';
	ft_draw(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	ft_interface(win, WHITE);
}
