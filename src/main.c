/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:45 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/04 15:38:23 by gperez           ###   ########.fr       */
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
	e->cam.fov = FOV;
	e->cam.dir = (t_vec){DIMX / tan(rad(e->cam.fov) / 2) * 2, DIMX / 2, DIMY / 2};
	e->cam.v_u = (t_vec){1, 1, 0};
	algo(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	env.labstart = NULL;
	parse(&env, argv[1]);
	if (ft_test(&env) == 0)
		init(&env);
	return (0);
}
