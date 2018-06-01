/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:37:08 by gperez            #+#    #+#             */
/*   Updated: 2018/06/01 13:53:31 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    algo(t_env *e)
{
	t_vec	bal;
	int		i_x;
	int		i_y;

	i_x = 0;
	bal = e->cam.dir;
	/*while (i_x < DIMX)
	{
		//ballayage par rapport centre ecran puis affichage du mur
		i_y = 0;
		while (i_y < DIMY)*/
			i_y = scan(e, apply((t_vec){0,0,i_x}, bal));
		/*i_x++;
	}*/
}
