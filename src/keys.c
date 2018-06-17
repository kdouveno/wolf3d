/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:35:47 by gperez            #+#    #+#             */
/*   Updated: 2018/06/15 19:58:51 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void k_direction (int key, t_env *e)
{
	(void)key;
	if (key == 0 || key == 113)
		e->cam.p = apply(vecpro(e->cam.v_u, -0.1), e->cam.p);
	else if (key == 1 || key == 115)
	{
	}
	else if (key == 2 || key == 100)
		e->cam.p = apply(vecpro(e->cam.v_u, 0.1), e->cam.p);
	else
	{
//	if (key == 13)
//		e->cam.p = apply(e->cam.p, e->cam.move);
	}
	algo(e);
//	printf("x: %f y: %f z: %f\n", e->cam.p.x, e->cam.p.y, e->cam.p.z);
//	printf("x: %f y: %f z: %f\n", e->cam.v_u.x, e->cam.v_u.y, e->cam.v_u.z);
}

void k_rotate (int key, t_env *e)
{
	if (key == 123 || key == 65361)
	{
		e->cam.v_u = ft_rotate_z(e->cam.v_u, rad(-ROT));
		e->cam.dir = ft_rotate_z(e->cam.dir, rad(-ROT));
	}
	else
	{
		e->cam.v_u = ft_rotate_z(e->cam.v_u, rad(ROT));
		e->cam.dir = ft_rotate_z(e->cam.dir, rad(ROT));
	}
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
	if (key == 0 || key == 1 || key == 2 || key == 13
		|| key == 100 || key == 115 || key == 122 || key == 113)
	{
		printf("d\n");
		k_direction(key, e);
	}
	else if (key == 53 || key == 65307)
		k_escape(e);
	else if (key == 123 || key == 65361 || key == 124 || key == 65363)
		k_rotate(key, e);
	return (0);
}
