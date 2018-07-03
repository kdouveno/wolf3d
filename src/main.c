/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:45 by kdouveno          #+#    #+#             */
/*   Updated: 2018/07/03 18:38:38 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(t_env *e, char *msg)
{
	(void)e;
	ft_putstr("\033[38;5;203m");
	ft_putendl(msg);
	ft_putstr("\033[37m");
	exit(0);
}

int		init(t_env *e)
{
	if ((e->mlx.ptr = mlx_init()) == NULL
	|| (e->mlx.win = mlx_new_window(e->mlx.ptr, DIMX,
		DIMY, "Wolf3D")) == NULL
	|| (e->mlx.imgptr = mlx_new_image(e->mlx.ptr, DIMX, DIMY)) == NULL
	|| (e->mlx.img = (int*)mlx_get_data_addr(e->mlx.imgptr, e->mlx.imgarg,
		e->mlx.imgarg + 1, e->mlx.imgarg + 2)) == NULL)
		error(e, MLX_ERROR);
	if (txt(e) == 1)
		error(e,TXT_ERROR);
	e->cam.fov = FOV;
	e->cam.dist = (double)(DIMX / 2) / tan(rad(FOV / 2));
	e->cam.dir = (t_vec){e->cam.dist, 0, 0};
	printf("v: %f %f %f\n", e->cam.dir.x, e->cam.dir.y, e->cam.dir.z);
	e->cam.v_u = (t_vec){0, 1, 0};
	algo(e);
	printf("x: %f y :%f\n",e->cam.p.x, e->cam.p.y);
	mlx_hook(e->mlx.win, KeyPress, KeyPressMask, my_key, e);
	mlx_loop(e->mlx.ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	env.labstart = NULL;
	parse(&env, argv[1]);
	ft_test(&env);
	init(&env);

	return (0);
}
