/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:45 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/20 14:45:33 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void	error(char *msg)
{
	putendl(msg);
	exit(0);
}

int	init(t_env *e)
{
	e->w = (t_wininfo){DIMX, DIMY};
	if ((e->mlx.ptr = mlx_init()) == NULL
	|| (e->mlx.win = mlx_new_window(e->mlx.ptr, e->w.x,
		e->w.y, "Wolf3D")) == NULL
	|| (e->mlx.iptr = mlx_new_image(e->mlx.ptr, e->w.x, e->w.y)) == NULL
	|| (e->mlx.img = (int*)mlx_get_data_addr(e->mlx.iptr, e->mlx.imgul,
		e->mlx.imgul + 1, e->mlx.imgul + 2)) == NULL)
		exit(0);
	e->s = (t_scene){NULL, NULL, {}, 0};
	mlx_key_hook(e->mlx.win, &key_hook, e);
	return (0);
}

int		main(int argc, char const **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	init(&env);

	return (0);
}
