/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:35:13 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/29 12:14:57 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	add_peer(t_env *e, t_pos *pos)
{
	t_peer *out;

	if (!(out = (t_peer*)malloc(sizeof(t_peer))))
		error(e, MALLOC_ERROR);
	*out = (t_peer){pos->cur, pos->cur->obj.meta[0], NULL};
	out->next = pos->peer;
	pos->peer = out;
}

void	check_peer(t_env *e, t_pos *pos)
{
	t_peer	*pb;
	int i;

	i = 0;
	while (g_meta_chars[i].c != pos->cur->obj.type)
		i++;
	pb = pos->peer;
	ft_putchar(pos->cur->obj.type);
	while (pb && g_meta_chars[i].match != 0 &&
		g_meta_chars[i].match != pb->base->obj.type)
		pb = pb->next;
	if (pb && (g_meta_chars[i].match == '\0' || pb->id == pos->cur->obj.meta[0]))
	{
		if (g_meta_chars[i].match != 0)
			pb->base->obj.cor = 0;
		pos->cur->obj.cor = 0;
	}
	else if (g_meta_chars[i].match != 0)
		add_peer(e, pos);
}
