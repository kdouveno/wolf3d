/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:55:47 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/25 13:42:16 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_base	**get_portal_base(t_base *b)
{
	return (get_base(b, b->obj.dir));
}

t_base	**get_base(t_base *b, t_metadir d)
{
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
	printf("pos->... %d\n", pos->l_l->obj.type == 'p');
	*out = (t_peer){pos->l_l, pos->l_l->obj.meta[0], NULL};
	out->next = pos->peer;
	pos->peer = out;
}

void	mega_link_portals(t_pos *pos, t_peer *pb)
{
	t_base	*start;
	t_base	*tmp;

	printf("C'est une sortie principale\n");
	if (!(pb->base->obj.meta[1] & 6))
		return ;
	start = pb->base;
	while (start)
	{
		tmp = *get_portal_base(start);
		printf("next: %p\n", tmp);
		if (start->obj.meta[1] & 6)
		{
			printf("La meta: %d\n", start->obj.meta[1]);
			(*get_portal_base(start)) = pos->l_l;
			start->obj.cor = 0;
			if (start->obj.meta[1] & 2)
			{
				(*get_portal_base(pos->l_l)) = start;
				pos->l_l->obj.cor = 0;
			}
		}
		start = tmp;
	}
}

void	check_portals(t_env *e, t_pos *pos, t_peer *pb)
{
	if ((*(get_portal_base(pos->l_l)))->obj.type != 'w')
		error(e, PORTAL_ERROR);
	if (pos->l_l->obj.meta[1] & 6)
	{
		if (pb->base->obj.meta[1] & 6)
		{
			(*get_portal_base(pos->l_l)) = *get_portal_base(pb->base);
			(*get_portal_base(pb->base)) = pos->l_l;
		}
		else
		{
			(*get_portal_base(pos->l_l)) = pb->base;
			pos->l_l->obj.cor = 0;
		}
	}
	else
		mega_link_portals(pos, pb);
}

void	check_peer(t_env *e, t_pos *pos)
{
	t_peer	*pb;
	int		i;

	i = 0;
	if (!pos->l_l)
		return ;
	while (g_meta_chars[i].c != pos->l_l->obj.type)
		i++;
	pb = pos->peer;
	while (pb && g_meta_chars[i].match
		&& g_meta_chars[i].match != pb->base->obj.type
		&& pb->id != pos->l_l->obj.meta[0])
		pb = pb->next;
	if (pb || g_meta_chars[i].match == '\0')
	{
		if (g_meta_chars[i].match != 0)
			pb->base->obj.cor = 0;
		pos->l_l->obj.cor = 0;
	}
	else
		add_peer(e, pos);
}
