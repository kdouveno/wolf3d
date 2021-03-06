/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/07/08 16:59:39 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	dist(t_pt p1, t_pt p2)
{
	return (hypot(p1.x - p2.x, p1.y - p2.y));
}

void	display(t_env *e, int i_x, t_pt_w ptw, t_vec bal)
{
	double	h;
	int		s_w;
	int		e_w;
	int		i;

	//bal = apply(vecpro((t_vec){0,0,1}, -DIMY / 2), bal);
	i = 0;
	h = e->cam.dist / (dist(e->cam.p, ptw.p)
		* cos(atan((i_x - DIMX / 2) / e->cam.dist)));
	s_w = h > DIMY ? 0 : (DIMY - h) / 2;
	e_w = h > DIMY ? DIMY : (DIMY + h) / 2;
	while (i < DIMY)
	{
		if (i < s_w)
			floor_casting(e, ptw, i_x, i);
		else if (i < e_w  - 1 || e_w == DIMY)
			put_txt_wall(e, ptw, i_x, i, i - s_w, h, bal);
		else
			e->mlx.img[i * DIMX + i_x] = 0x550F44;
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
		display(e, i_x, scan(e, bal), bal);
		i_x++;
	}
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
}
