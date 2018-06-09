/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/06/09 18:23:10 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_base	*check_u(t_base **b_wall)
{
	t_base *t;

	t = *b_wall;
	t = t->yu;
	*b_wall = t;
	if (t->next == NULL)
		return (t);
	else
		return (NULL);
}

static t_base	*check_r(t_base **b_wall)
{
	t_base *t;

	t = *b_wall;
	t = t->xu;
	*b_wall = t;
	if (t->next == NULL)
		return (t);
	else
		return (NULL);
}

static t_base	*check_d(t_base **b_wall)
{
	t_base *t;

	t = *b_wall;
	t = t->yd;
	*b_wall = t;
	if (t->next == NULL)
		return (t);
	else
		return (NULL);
}

static t_base	*check_l(t_base **b_wall)
{
	t_base *t;

	t = *b_wall;
	t = t->xd;
	*b_wall = t;
	if (t->next == NULL)
		return (t);
	else
		return (NULL);
}

static t_base	*check_dia4(t_base **b_wall, int dir)
{
	if (dir == UP_LEFT)
	{
		if (check_l(b_wall) != NULL)
			return(*b_wall);
		if (check_u(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
	else
	{
		if (check_l(b_wall) != NULL)
			return(*b_wall);
		if (check_d(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
}

static t_base	*check_dia3(t_base **b_wall, int dir)
{
	if (dir == UP_RIGHT)
	{
		if (check_r(b_wall) != NULL)
			return(*b_wall);
		if (check_u(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
	else
	{
		if (check_r(b_wall) != NULL)
			return(*b_wall);
		if (check_d(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
}

static t_base	*check_dia2(t_base **b_wall, int dir)
{
	if (dir == UP_LEFT)
	{
		if (check_u(b_wall) != NULL)
			return(*b_wall);
		if (check_l(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
	else if (dir == UP_RIGHT)
	{
		if (check_u(b_wall) != NULL)
			return(*b_wall);
		if (check_r(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
	else if (dir == DOWN_RIGHT)
	{
		if (check_d(b_wall) != NULL)
			return(*b_wall);
		if (check_r(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
	else
	{
		if (check_d(b_wall) != NULL)
			return(*b_wall);
		if (check_l(b_wall) != NULL)
			return(*b_wall);
		return (NULL);
	}
}
static t_base	*check_dia(t_base **b_wall, int dir, t_vec v, t_pt *old)
{
	double t;
	double x;
	double y;
	t_base *t_base;

	t_base = *b_wall;
	y = (dir == UP_LEFT || dir == UP_RIGHT) ? t_base->m.y : t_base->m.y + 1;
	t = (y - old->y) / v.y;
	x = v.x * t + old->x;

	printf("x : %f \n",x);
	printf("y : %f \n",y);
	if ((int)x == (int)old->x)
		return (check_dia2(b_wall, dir));
	else if ((int)x > (int)old->x)
		return (check_dia3(b_wall, dir));
	else if ((int)x < (int)old->x)
		return (check_dia4(b_wall, dir));
	return (NULL);
}


static t_base	*check_wall(t_base **b_wall, int dir, t_vec v, t_pt *old)
{
	if (dir == UP)
		return(check_u(b_wall));
	else if (dir == RIGHT)
		return(check_r(b_wall));
	else if (dir == DOWN)
		return(check_d(b_wall));
	else if (dir == LEFT)
		return(check_l(b_wall));
	else
		return (check_dia(b_wall, dir, v, old));
}

static int		check_base(t_vec v, t_pt *old, t_pt *p)
{
	int s;

	s = 0;
	while (((int)p->x == (int)old->x && (int)p->y == (int)old->y) || s == 0)
	{
		*old = (t_pt){p->x, p->y, p->z};
		*p = apply(v, *p);
		s = 1;
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
	t_base	*save;

	b_wall = e->cam.cur;
	v = ft_norm_vec(v);
	p = e->cam.p;
	old = (t_pt){p.x, p.y, p.z};
	printf("v.x = %f\n v.y = %f\n", v.x, v.y);
	while ((save = check_wall(&b_wall, check_base(v, &old, &p), v, &old)) == NULL)
	{
	}
	printf("x : %f\n y : %f\n",save->m.x, save->m.y);
	return (0);
}
