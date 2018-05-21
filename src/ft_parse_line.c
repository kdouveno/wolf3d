/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:53:03 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/21 18:06:03 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    base_left(t_env *e, t_pos *pos)
{
	if (pos->l == NULL || (pos->l->m.x - pos->x * POS != 1))

	else

}

void    base_up(t_env *e, t_pos *pos)
{
	if (pos->l_l == NULL || pos->l_l->m.y - pos->y * POS != 1)
}

void	add_base(t_env *e, t_pos *pos, char c)
{
	t_base out;
	t_base up;

	up.m = (t_pt){pos.x * PRES, pos.y * PRES, 1};
	out.m = (t_pt){pos.x * PRES, pos.y * PRES, 0};
	up.n = (t_vec){0, 0, -1};
	out.n = (t_vec){0, 0, 1};
	if (!e->lab)
	{
		if (!(e->lab = (t_base*)malloc(sizeof(t_base))))
			error(MALLOC_ERROR);
		*e->lab = out;
	}
	if (!last.l)
		last.l = e->lab;

}
