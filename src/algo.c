/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/06/15 19:50:26 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    algo(t_env *e)
{
	t_vec	bal;
	int		i_x;

	i_x = 0;
	bal = e->cam.dir;
	while (i_x < DIMX)
		scan(e, (bal = apply(e->cam.v_u, bal)), i_x++);
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win, e->mlx.imgptr, 0, 0);
}
