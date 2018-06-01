/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/06/01 17:32:36 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		check_u(t_base *b_wall, int dir)
{
	b_wall = b_wall->yu != NULL ? b_wall->yu : b_wall;
	return (b_wall->yu == NULL);
}

static int		check_r(t_base *b_wall, int dir)
{
	b_wall = b_wall->xu != NULL ? b_wall->xu : b_wall;
	return (b_wall->xu == NULL);
}

static int		check_d(t_base *b_wall, int dir)
{
	b_wall = b_wall->yd != NULL ? b_wall->yd : b_wall;
	return (b_wall->yd == NULL);
}

static int		check_l(t_base *b_wall, int dir)
{
	b_wall = b_wall->xd != NULL ? b_wall->xd : b_wall;
	return (b_wall->xd == NULL);
}

static int		check_dia(t_base *b_wall, int dir)
{
}


static int		check_wall(t_base *b_wall, int dir)
{
	if (dir == 1)
		check_u(b_wall, dir);
	else if (dir == 2)
		check_r(b_wall, dir);
	else if (dir == 3)
		check_d(b_wall, dir);
	else if (dir == 4)
		check_l(b_wall, dir);
	else
		check_dia(b_wall, dir);
}

static int		check_base(t_vec v, t_pt *old, t_pt *p)
{
	while ((int)p->x == (int)old->x && (int)p->y == (int)old->y)
	{
		*old = (t_pt){p->x, p->y, p->z};
		*p = apply(v, *p);
		printf("old : %d %d %d\n", (int)old->x, (int)old->y, (int)old->z);
		printf("p : %d %d %d\n", (int)p->x, (int)p->y, (int)p->z);
	}
	if ((int)p->x != (int)old->x && (int)p->y != (int)old->y)
	{
		if ((int)p->x < (int)old->x && (int)p->y < (int)old->y)
			return (UP_LEFT);
		else if ((int)p->x > (int)old->x && (int)p->y < (int)old->y)
			return (UP_RIGHT);
		else if ((int)p->x > (int)old->x && (int)p->y > (int)old->y)
			return (DOWN_RIGHT);
		else
			return (DOWN_LEFT);
	}
	else if ((int)p->x != (int)old->x)
		return((int)p->x > (int)old->x ? RIGHT : LEFT);
	else
		return((int)p->y < (int)old->y ? UP : DOWN);
}

int		scan(t_env *e, t_vec v)
{
	t_pt	p;
	t_pt	old;
	t_base	*b_wall;

	b_wall = e->cam->cur;
	v = ft_norm_vec(v);
	p = e->cam.p;
	old = (t_pt){p.x, p.y, p.z};
	printf("%d\n", check_base(v, &old, &p));
	return (0);
}
