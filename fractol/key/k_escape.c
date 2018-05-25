/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_escape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:32:12 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:43:39 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	k_escape(t_window *win)
{
	free(win->fractal);
	free(win->coords->pal_color);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(4);
}
