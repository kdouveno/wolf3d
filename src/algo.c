/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/06/25 16:18:20 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	dist(t_pt p1, t_pt p2)
{
	return (hypot(p1.x - p2.x, p1.y - p2.y));
}

void	display(t_env *e, int i_x, t_pt_v ptv, double ang)
{
	double	h;
	int		s_w;
	int		e_w;
	int		i;

	i = 0;
	h = e->cam.dist / (dist(e->cam.p, ptv.p) * cos(ang));
	s_w = h > DIMY ? 0 : (DIMY - h) / 2;
	e_w = h > DIMY ? DIMY - 1 : (DIMY + h) / 2;
	while (i < DIMY)
	{
		/*if (i_x == DIMX / 2)
			e->mlx.img[i * DIMX + i_x] = 0xFF0000;
		else
		{*/
			if (i < s_w)
				e->mlx.img[i * DIMX + i_x] = 0x0022F5;
			else if (i < e_w)
				put_txt_wall(e, ptv, i_x, i, s_w, h);
			else
				e->mlx.img[i * DIMX + i_x] = 0x111111;
		//}
		i++;
	}
}

void	algo(t_env *e)
{
	t_vec	bal;
	int		i_x;

	i_x = 0;
	bal = apply(vecpro(e->cam.v_u, -DIMX / 2), e->cam.dir);
	while (i_x < DIMX)
	{
		bal = apply(e->cam.v_u, bal);
		display(e, i_x, scan(e, bal), atan((i_x - DIMX / 2) / e->cam.dist));
		i_x++;
	}
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
}
