/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:48:07 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/09 18:01:43 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_base	*add_wall(t_env *e, t_base *base)
{
	t_base	*out;

	if (!(out = (t_base*)malloc(sizeof(t_base))))
		error(e, MALLOC_ERROR);
	*out = (t_base){{}, {}, {'w', 0, {}, 0}, {}, NULL, NULL, NULL, NULL,
		base, NULL};
	return (out);
}

void	wall_left(t_env *e, t_pos *pos)
{
	t_base	*w;

	if (pos->l == NULL || (pos->x - pos->l->m.x != 1)
	|| pos->y != pos->l->m.y)
	{
		w = add_wall(e, pos->cur);
		w->n = (t_vec){1, 0, 0};
		w->m = (t_vec){pos->cur->m.x, pos->cur->m.y, pos->cur->m.z};
		pos->cur->xd = w;
		if (pos->l == NULL)
			return ;
		w = add_wall(e, pos->cur);
		w->n = (t_vec){1, 0, 0};
		w->m = (t_vec){pos->l->m.x + 1, pos->l->m.y + 1,
			pos->l->m.z};
		pos->l->xu = w;
	}
	else
	{
		pos->cur->xd = pos->l;
		pos->l->xu = pos->cur;
	}
}

void	wall_up(t_env *e, t_pos *pos)
{
	t_base	*w;

	if (pos->l_l == NULL || (pos->x != pos->l_l->m.x)
	|| pos->y - pos->l_l->m.y != 1)
	{
		w = add_wall(e, pos->cur);
		w->n = (t_vec){0, 1, 0};
		w->m = (t_vec){pos->cur->m.x, pos->cur->m.y, pos->cur->m.z};
		pos->cur->yu = w;
		if (pos->l_l == NULL)
			return ;
		w = add_wall(e, pos->cur);
		w->n = (t_vec){0, 1, 0};
		w->m = (t_vec){pos->l_l->m.x + 1, pos->l_l->m.y + 1,
			pos->l_l->m.z};
		pos->l_l->yd = w;
	}
	else
	{
		pos->cur->yu = pos->l_l;
		pos->l_l->yd = pos->cur;
	}
}
