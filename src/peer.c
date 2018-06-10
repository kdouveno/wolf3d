/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:55:47 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/10 16:24:55 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	check_peer(t_env *e, t_pos *pos)
{
	t_peer	*pb;
	int		i;

	i = 0;
	if (!pos->l_l)
		return ;
	printf("'%c' %d %d %d\t%d %d, %d\n", pos->l_l->obj.type,
	(int)pos->l_l->m.x, (int)pos->l_l->m.y, (int)pos->l_l->m.z,
	pos->l_l->obj.meta[0], pos->l_l->obj.meta[1], pos->l_l->obj.cor);
	while (g_meta_chars[i].c != pos->l_l->obj.type)
		i++;
	pb = pos->peer;
	while (pb && g_meta_chars[i].match != 0 &&
		g_meta_chars[i].match != pb->base->obj.type)
		pb = pb->next;
	if (pb && (g_meta_chars[i].match == '\0'
	|| pb->id == pos->l_l->obj.meta[0]))
	{
		if (g_meta_chars[i].match != 0)
			pb->base->obj.cor = 0;
		pos->l_l->obj.cor = 0;
	}
	else if (g_meta_chars[i].match != 0)
		add_peer(e, pos);
}
