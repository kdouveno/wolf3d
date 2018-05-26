/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:53:03 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/26 17:48:31 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_meta(t_env *e, t_pos *pos, char **tab, char c)
{
	int i;
	int i_m;

	i = 0;
	i_m = 0;
	pos->cur->obj.type = c;
	while (c != g_meta_chars[i].c)
		i++;
	if (g_meta_chars[i].has_dir && tab[pos->tabi])
		pos->cur->obj.dir = ft_atoi(tab[pos->tabi++]);
	else if (g_meta_chars[i].has_dir)
		error(e, FILE_ERROR);
	while (g_meta_chars[i].nbrparam > i_m)
	{
		if (tab != NULL && tab[pos->tabi])
			pos->cur->obj.meta[i_m] = ft_atoi(tab[pos->tabi]);
		else
			error(e, FILE_ERROR);
		i_m++;
	}
}

void	manage_ll(t_env *e, t_pos *pos)
{
	static int	b;

	if (pos->y > 0 && !b)
	{
		b = 1;
		pos->l_l = e->labstart;
	}
	while (b && (pos->l_l->m.y < (pos->y - 1) * PRES
	|| pos->l_l->m.x < pos->x * PRES))
		pos->l_l = pos->l_l->next;
}

void	add_base(t_env *e, t_pos *pos, char **tab, char c)
{
	if (!(pos->cur = (t_base*)malloc(sizeof(t_base)))
	|| !(pos->cur->ceil = (t_base*)malloc(sizeof(t_base))))
		error(e, MALLOC_ERROR);
	pos->cur->m = (t_pt){pos->x * PRES, pos->y * PRES, 0};
	pos->cur->n = (t_vec){0, 0, 1};
	pos->cur->ceil->m = (t_pt){pos->x * PRES, pos->y * PRES, PRES};
	pos->cur->ceil->n = pos->cur->n;
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

	pos->l_l = pos->l_l->next;
	w = add_wall(e, pos);
	w->n = (t_vec){1, 0, 0};
	w->m = (t_vec){pos->l->m.x + PRES, pos->l->m.y + PRES, pos->l->m.z};
	pos->l->xu = w;
	while (pos->l_l)
	{
		w = add_wall(e, pos);
		w->n = (t_vec){0, 1, 0};
		w->m = (t_vec){pos->l_l->m.x + PRES, pos->l_l->m.y + PRES,
			pos->l_l->m.z};
		pos->l_l->yd = w;
		pos->l_l = pos->l_l->next;
	}
}
