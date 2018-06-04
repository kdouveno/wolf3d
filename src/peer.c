/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:55:47 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/04 15:33:42 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_base	**get_base(t_base *b)
{
	t_metadir d;

	d = b->obj.dir;
	if (d == UP)
		return (&b->yu);
	else if (d == RIGHT)
		return (&b->xu);
	else if (d == DOWN)
		return (&b->yd);
	else if (d == LEFT)
		return (&b->xd);
	return (NULL);
}

void	add_peer(t_env *e, t_pos *pos)
{
	t_peer *out;

	if (!(out = (t_peer*)malloc(sizeof(t_peer))))
		error(e, MALLOC_ERROR);
	if (pos->cur->obj.type == 'p')
		(*get_base(pos->cur)) = NULL;
	*out = (t_peer){pos->cur, pos->cur->obj.meta[0], NULL};
	out->next = pos->peer;
	pos->peer = out;
}

void	pe_portals(t_pos *pos, t_peer *pb)
{
	free(*get_base(pos->cur));
	if (pb->base->obj.meta[1] & 4)
	{
		(*get_base(pos->cur)) = pb->base;
		pb->base = pos->cur;
	}
	else if (~pb->base->obj.meta[1] & 6)
	{
		(*get_base(pos->cur)) = pb->base;
		(*get_base(pb->base)) = pos->cur;
		pos->cur->obj.cor = 0;
		pb->base->obj.cor = 0;
	}
}

void	mega_link_portals(t_pos *pos, t_peer *pb)
{
	t_base	*start;
	t_base	*tmp;
	int		id;

	if (~pb->base->obj.meta[1] & 6)
		return ;
	start = pb->base;
	id = pb->id;
	while (start->obj.type == 'p' && start->obj.meta[0] == id)
	{
		tmp = *get_base(start);
		if (start->obj.meta[1] & 6)
		{
			(*get_base(start)) = pos->cur;
			start->obj.cor = 0;
			if (start->obj.meta[1] & 2)
			{
				(*get_base(pos->cur)) = start;
				pos->cur->obj.cor = 0;
				start->obj.cor = 0;
			}
		}
	}
}

void	check_portals(t_pos *pos, t_peer *pb)
{
	if (pos->cur->obj.meta[1] & 4)
	{
		free((*get_base(pos->cur)));
		if (pb->base->obj.meta[1] & 6)
		{
			(*get_base(pos->cur)) = *get_base(pb->base);
			(*get_base(pb->base)) = pos->cur;
		}
		else
		{
			(*get_base(pos->cur)) = pb->base;
			pos->cur->obj.cor = 0;
		}
	}
	else if (pos->cur->obj.meta[1] & 2)
		pe_portals(pos, pb);
	else if (~pos->cur->obj.meta[1] & 6)
		mega_link_portals(pos, pb);
}

void	check_peer(t_env *e, t_pos *pos)
{
	t_peer	*pb;
	int		i;

	i = 0;
	while (g_meta_chars[i].c != pos->cur->obj.type)
		i++;
	pb = pos->peer;
	while (pb && g_meta_chars[i].match != 0 &&
		g_meta_chars[i].match != pb->base->obj.type)
		pb = pb->next;
	if (pb && (g_meta_chars[i].match == '\0'
	|| pb->id == pos->cur->obj.meta[0]))
	{
		if (g_meta_chars[i].c == 'p')
			check_portals(pos, pb);
		else
		{
			if (g_meta_chars[i].match != 0)
				pb->base->obj.cor = 0;
			pos->cur->obj.cor = 0;
		}
	}
	else if (g_meta_chars[i].match != 0)
		add_peer(e, pos);
}
