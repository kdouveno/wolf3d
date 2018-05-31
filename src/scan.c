/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/05/31 17:32:25 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		check_wall(t_env *e, t_pt *new, t_pt *p, int *i)
{
	while (new / PRES == p / PRES)
	{
		new = p;
		p = apply(v, p);
		i++;
	}

}

int		scan(t_env *e, t_vec v)
{
	t_pt	p;
	t_pt	new;
	int		i;
	int		d;

	v = ft_norm_vec(v, PRES);
	d = v.y / v.x;
	p = e->cam.p;
	new = p;
	while (check_wall(e, &new, &*, &i, &d) != 1)
	{

	}
}
