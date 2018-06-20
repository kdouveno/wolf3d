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

void	detect_wall(t_env *e, t_pt move)
{
	int lockx;
	int locky;

	lockx = 1;
	locky = 1;
	if (lockx == 1 && (int)move.x > (int)e->cam.p.x && (lockx = (e->cam.cur->xu->obj.type != 'w')))
		e->cam.cur = e->cam.cur->xu;
	else if (lockx == 1 && (int)move.x < (int)e->cam.p.x && (lockx = (e->cam.cur->xd->obj.type != 'w')))
		e->cam.cur = e->cam.cur->xd;
	if (locky == 1 && (int)move.y > (int)e->cam.p.y && (locky = (e->cam.cur->yd->obj.type != 'w')))
		e->cam.cur = e->cam.cur->yd;
	else if (locky == 1 && (int)move.y < (int)e->cam.p.y && (locky = (e->cam.cur->yu->obj.type != 'w')))
		e->cam.cur = e->cam.cur->yu;
	if(lockx == 1)
		e->cam.p.x = move.x;
	if(locky == 1)
		e->cam.p.y = move.y;
}

void	k_direction (int key, t_env *e)
{
	t_pt move;

	if (key == 0 || key == 113)
		move = apply(vecpro(e->cam.v_u, -0.1), e->cam.p);
	else if (key == 1 || key == 115)
		move = apply(vecpro(ft_neg_vec(e->cam.dir), MOV), e->cam.p);
	else if (key == 2 || key == 100)
		move = apply(vecpro(e->cam.v_u, 0.1), e->cam.p);
	else
		move = apply(vecpro(e->cam.dir, MOV), e->cam.p);
	if (move.x > 0 && move.y > 0)
		detect_wall(e, move);
	algo(e);
	printf("x: %f y: %f z: %f\n", e->cam.p.x, e->cam.p.y, e->cam.p.z);
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
		k_direction(key, e);
	else if (key == 53 || key == 65307)
		k_escape(e);
	else if (key == 123 || key == 65361 || key == 124 || key == 65363)
		k_rotate(key, e);
	return (0);
}
