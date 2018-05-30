/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/05/30 17:01:45 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    algo(t_env *e)
{
	t_pt	bal;
	int		i_y;
	int		i_x;

	i_x = 0;
	bal = apply(e->dir, e->p);
	while (i_x < DIMX)
	{
		//ballayage par rapport centre ecran puis affichage du mur

		i_y = 0;
		while (i_y < DIMY)
		{

			i_y++;
		}
		i_x++;
	}
}

t_pt	apply_x(int x, t_pt p)
{
	return ((t_pt){p.x + x, p.y, p.z});
}

t_pt	apply_y(int y, t_pt p)
{
	return ((t_pt){p.x, p.y + y, p.z});
}

t_pt	apply(t_vec v, t_pt p)
{
	return ((t_pt){p.x + v.x, p.y + v.y, p.z + v.z});
}

t_vec	vecpro(t_vec v, double a)
{
	return ((t_vec){v.x * a, v.y * a, v.z * a});
}
