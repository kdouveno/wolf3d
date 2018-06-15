/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:53:03 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/15 20:15:32 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_meta(t_env *e, t_pos *pos, char **tab, char c)
{
	int i;
	int i_m;

	i = 0;
	while (c != g_meta_chars[i].c)
		i++;
	if (g_meta_chars[i].has_dir && tab[pos->tabi])
		pos->cur->obj.dir = ft_atoi(tab[pos->tabi++]);
	else if (g_meta_chars[i].has_dir)
		error(e, FILE_ERROR);
	i_m = 0;
	while (g_meta_chars[i].nbrparam > i_m)
	{
		if (tab != NULL && tab[pos->tabi])
			pos->cur->obj.meta[i_m] = ft_atoi(tab[pos->tabi++]);
		else
			error(e, FILE_ERROR);
		i_m++;
	}
	if (pos->cur->obj.type == 's')
	{
		e->cam.p = (t_pt){(pos->cur->m.x + 0.5), (pos->cur->m.y + 0.5),
			pos->cur->m.z};
		e->cam.cur = pos->cur;
	}
}

void	manage_ll(t_env *e, t_pos *pos)
{
	static int	b;
	int			a;

	a = 0;
	if (pos->y > e->labstart->m.y && !b)
	{
		b = 1;
		pos->l_l = e->labstart;
		a = 1;
	}
	while (b && (pos->l_l->m.y < (pos->y - 1)
	|| pos->l_l->m.x < pos->x))
	{
		if (a)
			pos->l_l->yd = add_wall(e, pos->l_l);

		check_peer(e, pos);
		pos->l_l = pos->l_l->next;
		a = 1;
	}
}

void	add_base(t_env *e, t_pos *pos, char **tab, char c)
{
	if (!(pos->cur = (t_base*)malloc(sizeof(t_base)))
	|| !(pos->cur->ceil = (t_base*)malloc(sizeof(t_base))))
		error(e, MALLOC_ERROR);
	pos->cur->m = (t_pt){pos->x, pos->y, 0};
	pos->cur->n = (t_vec){0, 0, 1};
	pos->cur->ceil->m = (t_pt){pos->x, pos->y, 1};
	pos->cur->ceil->n = pos->cur->n;
	pos->cur->obj = (t_obj){c, 0, {0, 0}, 1};
	set_meta(e, pos, tab, c);
	if (!e->labstart)
		e->labstart = pos->cur;
	else
		pos->l->next = pos->cur;
	manage_ll(e, pos);
	wall_up(e, pos);
	wall_left(e, pos);
	pos->l = pos->cur;
}

void	finish(t_env *e, t_pos *pos)
{
	t_base *w;

	if (!pos->l_l)
		pos->l_l = e->labstart;
	pos->l_l = pos->l_l->next;
	w = add_wall(e, pos->l_l);
	w->n = (t_vec){1, 0, 0};
	w->m = (t_vec){pos->l->m.x + 1, pos->l->m.y + 1, pos->l->m.z};
	pos->l->xu = w;
	while (pos->l_l)
	{
		w = add_wall(e, pos->l_l);
		w->n = (t_vec){0, 1, 0};
		w->m = (t_vec){pos->l_l->m.x + 1, pos->l_l->m.y + 1,
			pos->l_l->m.z};
		pos->l_l->yd = w;
		check_peer(e, pos);
		pos->l_l = pos->l_l->next;
	}
}
