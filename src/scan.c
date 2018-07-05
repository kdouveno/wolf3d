/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/07/03 18:14:16 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pt_w	vertical_bitch(t_env *e, t_base *b, t_metadir dir)
{
	while ((*get_base(b, dir))->obj.type != 'w')
		b = *get_base(b, dir);
	return ((t_pt_w){(t_pt){e->cam.p.x, b->m.x, 0.5}, *b});
}

t_pt_w	entre_deux(t_metadir dir, t_base *start, double val[4])
{
	if (dir == UP || dir == DOWN)
		return ((t_pt_w){(t_pt){(start->m.y - val[1]) / val[0],
			start->m.y, 0.5}, *start});
	else
		return ((t_pt_w){(t_pt){start->m.x, val[3], 0.5}, *start});
}

t_pt_w	scan(t_env *e, t_vec v)
{
	t_base		*start;
	double		val[4];
	int			y;
	t_metadir	dir;

	if ((int)v.x == 0)
		return (vertical_bitch(e, e->cam.cur, v.y > 0 ? DOWN : UP));
	else
	{
		start = e->cam.cur;
		val[0] = v.y / v.x;
		val[1] = -v.y * e->cam.p.x / v.x + e->cam.p.y;
		val[2] = e->cam.cur->m.x + (v.x > 0 ? 1 : 0);
		while (start->obj.type != 'w')
		{
			val[3] = val[0] * val[2] + val[1];
			y = (int)val[3];
			if (y > start->m.y)
				dir = DOWN;
			else if (y < start->m.y)
				dir = UP;
			else
			{
				dir = v.x > 0 ? RIGHT : LEFT;
				val[2] += v.x > 0 ? 1 : -1;
			}
			start = *get_base(start, dir);
		}
	}
	return (entre_deux(dir, start, val));
}
