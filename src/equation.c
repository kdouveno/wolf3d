/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:03:33 by gperez            #+#    #+#             */
/*   Updated: 2018/06/01 14:46:34 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec		ft_norm_vec(t_vec v)
{
	double a;

	a = sqrt(v.x * v.x + v.y * v.y);
	return ((t_vec){v.x / a, v.y / a, v.z});
}

t_vec		ft_neg_vec(t_vec v)
{
	return ((t_vec){-v.x, -v.y, -v.z});
}

t_pt	apply(t_vec v, t_pt p)
{
	return ((t_pt){p.x + v.x, p.y + v.y, p.z + v.z});
}

t_vec	vecpro(t_vec v, double a)
{
	return ((t_vec){v.x * a, v.y * a, v.z * a});
}

double  rad(double deg)
{
	return (deg * 2 * M_PI / 360);
}

t_vec		ft_rotate_z(t_vec v, double teta)
{
	return((t_vec){cos(teta) * v.x - sin(teta) * v.y,
		sin(teta) * v.x + cos(teta) * v.y, v.z});
}
