/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:31:08 by gperez            #+#    #+#             */
/*   Updated: 2018/04/21 15:10:54 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*ft_random_color(t_window *win)
{
	int		*pal_color;
	t_color	color;
	int		nbr;
	int		cmpt_nbr;
	int		cmpt_color;

	win->coords->nbr_color = 5;
	pal_color = malloc(sizeof(int) * 5);
	cmpt_nbr = 0;
	cmpt_color = 0;
	while (cmpt_color < 5)
	{
		while (cmpt_nbr < 3)
		{
			nbr = rand() % 255;
			color.color_rgba[cmpt_nbr] = nbr;
			cmpt_nbr++;
		}
		cmpt_nbr = 0;
		pal_color[cmpt_color] = color.color;
		cmpt_color++;
	}
	return (pal_color);
}
