/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:53:03 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/25 15:56:51 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void   add_wall(t_env *e, t_pos *pos, char dir)
{
	t_base	*w;

	if ((w = malloc(sizeof(t_base))) == NULL)
		error(e, MALLOC_ERROR);
	w->obj.type = 0;
	w->ceil = pos->cur;
	if (dir == 'l' || dir == 'r')
	{
		w->n = (t_pt){0, 0, 1};
		if (dir == 'l')
			pos->cur->xd = w;
		else
			pos->cur->xu = w;
	}
	else if (dir == 'u' || dir == 'd')
	{
		w->n = (t_pt){0, 1, 0};
		if (dir == 'u')
			pos->cur->yu = w;
		else
			pos->cur->yd = w;
	}
	w->m = (dir == 'l' || dir == 'u') ?
		(t_pt){pos->cur->m.x, pos->cur->m.y, pos->cur->m.z} :
		(t_pt){pos->cur->m.x, pos->cur->m.y + PRES, pos->cur->m.z + PRES};
}

void    wall_left(t_env *e, t_pos *pos)
{
	if (pos->l == NULL || (pos->l->m.x - pos->x * PRES != 1))
		add_wall(e, pos, 'l');
	else
		pos->l->xu = pos->cur;

}

void    wall_up(t_env *e, t_pos *pos)
{
	if (pos->l_l == NULL || pos->l_l->m.y - pos->y * PRES != 1)
		add_wall(e, pos, 'u');
	else
		pos->l_l->yd = pos->cur;
}
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
		if (tab[pos->tabi])
			pos->cur->obj.meta[i_m] = ft_atoi(tab[pos->tabi]);
		else
			error(e, FILE_ERROR);
		i_m++;
	}
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
	pos->l = pos->cur;
}
