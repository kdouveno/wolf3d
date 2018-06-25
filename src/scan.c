/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:43:52 by gperez            #+#    #+#             */
/*   Updated: 2018/06/25 16:18:47 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
/*
static t_base	*check_u(t_base **b_wall)
{
 	t_base *t;

 	t = *b_wall;
 	t = t->yu;
 	*b_wall = t;
 	if (t->obj.type == 'w')
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
 	if (t->obj.type == 'w')
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
 	if (t->obj.type == 'w')
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
 	if (t->obj.type == 'w')
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
 	}
 	else if (dir == DOWN_LEFT)
 	{
 		if (check_l(b_wall) != NULL)
 			return(*b_wall);
 		if (check_d(b_wall) != NULL)
 			return(*b_wall);
 	}
 	return (NULL);
 }

 static t_base	*check_dia3(t_base **b_wall, int dir)
 {
 	if (dir == UP_RIGHT)
 	{
 		if (check_r(b_wall) != NULL)
 			return(*b_wall);
 		if (check_u(b_wall) != NULL)
 			return(*b_wall);
 	}
 	else if (dir == DOWN_RIGHT)
 	{
 		if (check_r(b_wall) != NULL)
 			return(*b_wall);
 		if (check_d(b_wall) != NULL)
 			return(*b_wall);
 	}
 	return (NULL);
 }

 static t_base	*check_dia2(t_base **b_wall, int dir)
 {
 	if (dir == UP_LEFT)
 	{
 		if (check_u(b_wall) != NULL)
 			return(*b_wall);
 		if (check_l(b_wall) != NULL)
 			return(*b_wall);
 	}
 	else if (dir == UP_RIGHT)
 	{
 		if (check_u(b_wall) != NULL)
 			return(*b_wall);
 		if (check_r(b_wall) != NULL)
 			return(*b_wall);
 	}
 	else if (dir == DOWN_RIGHT)
 	{
 		if (check_d(b_wall) != NULL)
 			return(*b_wall);
 		if (check_r(b_wall) != NULL)
 			return(*b_wall);
 	}
 	else
 	{
 		if (check_d(b_wall) != NULL)
 			return(*b_wall);
 		if (check_l(b_wall) != NULL)
 			return(*b_wall);
 	}
 	return (NULL);
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

 void    display(t_env *e, t_vec v, double t, int i_x)
 {
 	double	h;
 	int		s_w;
 	int		e_w;
 	int		i;

 	i = 0;
 	(void)v;
 	h = e->cam.dist / t;

 	s_w = h > DIMY ? 0 : (DIMY - h) / 2;
 	e_w = h > DIMY ? DIMY - 1 : (DIMY + h) / 2;
 //	printf("s_w : %d, e_w : %d\n", s_w, e_w);
 	while (i < s_w)
 	{
 		//afficher pixel toit;
 		e->mlx.img[i * DIMX + i_x] = 0x1015FF;
 		i++;
 	}
 	while (i < e_w)
 	{
 		//afficher pixel mur;
 		e->mlx.img[i * DIMX + i_x] = 0xFFFFFF;
 		i++;
 	}
 	while (i < DIMY)
 	{
 		//afficher pixel sol;
 		e->mlx.img[i * DIMX + i_x] = 0xFFFF00;
 		i++;
 	}
 	e->cam.move = ft_norm_vec((t_vec){e->cam.dir.x, e->cam.dir.y + DIMX / 2,
 		e->cam.dir.z - DIMX / 2});
 //	printf("h : %f\n", h);
 }

 int		scan(t_env *e, t_vec v, int i_x)
 {
 	t_pt	p;
 	t_pt	old;
 	t_base	*b_wall;
 	t_base	*save;
 	double	t;
    int     i;

    i = 0;
 	b_wall = e->cam.cur;
 	v = ft_norm_vec(v);
 	p = e->cam.p;
 	old = (t_pt){p.x, p.y, p.z};
 //	printf("p.x = %f\np.y = %f\n", p.x, p.y);
 //	printf("v.x = %f\nv.y = %f\n", v.x, v.y);
 	while ((save = check_wall(&b_wall, check_base(v, &old, &p), v, &old)) == NULL)
 	{
        i++;
 	}
    //printf("i = %d\n", i);
 //	printf("plan x : %f y : %f z : %f\nvecteur du plan x: %f y : %f z : %f\n",save->m.x, save->m.y, save->m.z, save->n.x, save->n.y, save->n.z);
 //	printf("test: %f * %f + %f * %f\n",save->n.x, v.x, save->n.y, v.y);
 	t = -(save->n.x * e->cam.p.x + save->n.y * e->cam.p.y - (save->m.x * save->n.x + save->m.y * save->n.y))
 	/ (save->n.x * v.x + save->n.y * v.y);

 	// printf("t : %f\n", t);
 	display(e, v, t, i_x);
 	return (0);
}
*/

t_pt	vertical_bitch(t_env *e, t_base *b, t_metadir dir)
{
	while ((*get_base(b, dir))->obj.type != 'w')
		b = *get_base(b, dir);
	return ((t_pt){e->cam.p.x, b->m.x, 0.5});
}

t_pt	entre_deux(t_metadir dir, t_base *start, double val[4])
{
	if (dir == UP || dir == DOWN)
		return ((t_pt){(start->m.y - val[1]) / val[0],
			start->m.y, 0.5});
	else
		return ((t_pt){start->m.x, val[3], 0.5});
}

t_pt	scan(t_env *e, t_vec v)
{
	t_base		*start;
	double		val[4];
	int			y;
	t_metadir	dir;
	int			i_test;

	i_test = 0;
	if (v.x == 0)
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
			i_test++;
		}
	}
	return (entre_deux(dir, start, val));
}
