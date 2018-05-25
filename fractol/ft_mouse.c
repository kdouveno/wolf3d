/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:02:40 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 13:56:51 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			my_mouse(int button, int x, int y, t_window *win)
{
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		k_zoom(win, button);
	return (0);
}
