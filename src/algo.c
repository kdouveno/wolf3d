/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/06/19 15:23:56 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	dist(t_pt p1, t_pt p2)
{
	return (hypot(p1.x - p2.x, p1.y - p2.y));
}

void	display(t_env *e, int i_x, t_pt pt)
{
	double	h;
	int		s_w;
	int		e_w;
	int		i;

	i = 0;
	h = e->cam.dist / dist(e->cam.p, pt);
	s_w = h > DIMY ? 0 : (DIMY - h) / 2;
	e_w = h > DIMY ? DIMY - 1 : (DIMY + h) / 2;
	while (i < DIMY)
	{
		if (i < s_w)
			e->mlx.img[i * DIMX + i_x] = 0x1015FF;
		else if (i < e_w)
			e->mlx.img[i * DIMX + i_x] = 0xFFFFFF;
		else
			e->mlx.img[i * DIMX + i_x] = 0xFFFF00;
		i++;
	}
}

void	algo(t_env *e)
{
	t_vec	bal;
	int		i_x;

	i_x = 0;
	bal = e->cam.dir;
	while (i_x < DIMX)
		display(e, i_x++, scan(e, (bal = apply(e->cam.v_u, bal))));
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
}
