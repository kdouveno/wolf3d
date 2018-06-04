/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/06/04 18:24:30 by gperez           ###   ########.fr       */
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

static int		check_dia(t_base *b_wall, int dir, t_vec v, t_pt *old)
{
	double t;
	double x;
	double y;


	y = (dir == UP_LEFT || dir == UP_RIGHT) ? b_wall->m.y : b_wall->m.y + 1;
	t = (y - old->y) / v.y;
	x = v.x * t + old->x;

	printf("x : %f \n",x);
	printf("y : %f \n",y);
	if ((int)x == (int)old->x)
	{

		if (dir == UP_LEFT)
		{
			if (check_u(b_wall) == 1)
				return(1);
			if (check_l(b_wall) == 1)
				return(1);
			return (0);
		}
		else if (dir == UP_RIGHT)
		{
			if (check_u(b_wall) == 1)
				return(1);
			if (check_r(b_wall) == 1)
				return(1);
			return (0);
		}
		else if (dir == DOWN_RIGHT)
		{
			if (check_d(b_wall) == 1)
				return(1);
			if (check_r(b_wall) == 1)
				return(1);
			return (0);
		}
		else
		{
			if (check_d(b_wall) == 1)
				return(1);
			if (check_l(b_wall) == 1)
				return(1);
			return (0);
		}

	}
	else if ((int)x > (int)old->x)
	{
		if (dir == UP_RIGHT)
		{
			if (check_r(b_wall) == 1)
				return(1);
			if (check_u(b_wall) == 1)
				return(1);
			return (0);
		}
		else
		{
			if (check_r(b_wall) == 1)
				return(1);
			if (check_d(b_wall) == 1)
				return(1);
			return (0);
		}
	}
	else if ((int)x < (int)old->x)
	{
		if (dir == UP_LEFT)
		{
			if (check_l(b_wall) == 1)
				return(1);
			if (check_u(b_wall) == 1)
				return(1);
			return (0);
		}
		else
		{
			if (check_l(b_wall) == 1)
				return(1);
			if (check_d(b_wall) == 1)
				return(1);
			return (0);
		}
	}
	return (0);
}


static int		check_wall(t_base *b_wall, int dir, t_vec v, t_pt *old)
{
	if (dir == UP)
	{
		ft_putnbr(dir);
		ft_putchar('\n');
		return (check_u(b_wall));
	}
	else if (dir == RIGHT)
	{
		ft_putnbr(dir);
		ft_putchar('\n');
		return (check_r(b_wall));
	}
	else if (dir == DOWN)
	{
		ft_putnbr(dir);
		ft_putchar('\n');
		return (check_d(b_wall));
	}
	else if (dir == LEFT)
	{
		ft_putnbr(dir);
		ft_putchar('\n');
		return (check_l(b_wall));
	}
	else
	{
		ft_putnbr(dir);
		ft_putchar('\n');
		return (check_dia(b_wall, dir, v, old));
	}
}

static int		check_base(t_vec v, t_pt *old, t_pt *p)
{
	int s;

	s = 0;
	while (((int)p->x == (int)old->x && (int)p->y == (int)old->y) || s == 0)
	{
		*old = (t_pt){p->x, p->y, p->z};
		*p = apply(v, *p);
		printf("old : %f %f %f\n", old->x, old->y, old->z);
		printf("p : %f %f %f\n", p->x, p->y, p->z);
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
	int		test;

	b_wall = e->cam.cur;

	v = ft_norm_vec(v);
	p = e->cam.p;
	old = (t_pt){p.x, p.y, p.z};
	printf("v.x = %f\n v.y = %f\n", v.x, v.y);
	while ((test = check_wall(b_wall, check_base(v, &old, &p), v, &old)) != 1)
	{
		ft_putendl("on avance");
		ft_putnbr(test);
	}
	return (0);
}
