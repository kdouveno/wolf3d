/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:35:47 by gperez            #+#    #+#             */
/*   Updated: 2018/06/12 12:35:23 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void k_direction (int key, t_env *e)
{
	(void)key;
/*	if (key == 0)
	{

	}
	else if (key == 1)
	{

	}
	else if (key == 2)
	{

	}
	else
	{*/
	if (key == 13)
		e->cam.p = apply(e->cam.p, e->cam.move);
//	}
	algo(e);
}

void k_rotate (int key, t_env *e)
{
	if (key == 123)
		e->cam.dir = apply(e->cam.dir, (t_vec){0,-30,0});
	else
		e->cam.dir = apply(e->cam.dir, (t_vec){0,30,0});
	algo(e);
}

void	k_escape(t_env *e)
{
	mlx_destroy_image(e->mlx.ptr, e->mlx.imgptr);
	mlx_destroy_window(e->mlx.ptr, e->mlx.win);
	exit(4);
}

int my_key(int key, t_env *e)
{
	(void)e;
	printf("%d\n", key);
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		printf("d\n");
		k_direction(key, e);
	}
	else if (key == 53)
		k_escape(e);
	else if (key == 123 || key == 124)
		k_rotate(key, e);
	return (0);
}
