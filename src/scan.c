/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/06/04 15:38:15 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		check_u(t_base *b_wall)
{
	b_wall = b_wall->yu;
	return (b_wall->next == NULL);
}

static int		check_r(t_base *b_wall)
{
	b_wall = b_wall->xu;
	return (b_wall->next == NULL);
}

static int		check_d(t_base *b_wall)
{
	b_wall = b_wall->yd;
	return (b_wall->next == NULL);
}

static int		check_l(t_base *b_wall)
{
	b_wall = b_wall->xd;
	return (b_wall->next == NULL);
}

static int		check_dia(t_base *b_wall, int dir, t_vec v, t_pt old)
{
	double t;
	double x;
	double y;


	y = (dir == UP_LEFT || dir == UP_RIGHT) ? b_wall->m.y : b_wall->m.y + 1;
	t = (old.y - y) / v.y;
	x = v.x * t + old.x;

	if ((int)x == (int)old.x)
	{
		if (dir == UP_LEFT)
		{
			check_u(b_wall);
			check_l(b_wall);
		}
		if (dir == DOWN_LEFT)
		{
			check_l(b_wall);
			check_u(b_wall);
		}
	}
	else if ((int)x == (int)old.x)
	{
		check_r(b_wall);
	}
	else if (dir == DOWN)
		check_d(b_wall);
	else if (dir == LEFT)
		check_l(b_wall);

	return (0);
}


static int		check_wall(t_base *b_wall, int dir, t_vec v, t_pt old)
{
	if (dir == UP)
		return (check_u(b_wall));
	else if (dir == RIGHT)
		return (check_r(b_wall));
	else if (dir == DOWN)
		return (check_d(b_wall));
	else if (dir == LEFT)
		return (check_l(b_wall));
	else
		return (check_dia(b_wall, dir, v, old));
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

	b_wall = e->cam.cur;
	v = ft_norm_vec(v);
	p = e->cam.p;
	old = (t_pt){p.x, p.y, p.z};
	while(check_wall(b_wall, check_base(v, &old, &p), v, old) != 1)
	{
		ft_putendl("on avance");
	}
	return (0);
}
