/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:35:52 by gperez            #+#    #+#             */
/*   Updated: 2018/07/03 18:34:40 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		txt(t_env *e)
{
	int	w;
	int	h;

	w = TXT_L;
	h = TXT_L;
	if ((e->txt.wall1 =
	mlx_xpm_file_to_image(e->mlx.ptr, "textures/redbrick.xpm" ,&w ,&h))
	== NULL || (e->txt.wall2 =
	mlx_xpm_file_to_image(e->mlx.ptr, "textures/eagle.xpm" ,&w ,&h))
	== NULL || (e->txt.wall3 =
	mlx_xpm_file_to_image(e->mlx.ptr, "textures/mossy.xpm" ,&w ,&h))
	== NULL || (e->txt.wall4 =
	mlx_xpm_file_to_image(e->mlx.ptr, "textures/wood.xpm" ,&w ,&h))
	== NULL)
		return (1);
	e->txt.imgwall1 = (int*)mlx_get_data_addr(e->txt.wall1, e->mlx.imgarg,
	e->mlx.imgarg + 1, e->mlx.imgarg + 2);
	e->txt.imgwall2 = (int*)mlx_get_data_addr(e->txt.wall2, e->mlx.imgarg,
	e->mlx.imgarg + 1, e->mlx.imgarg + 2);
	e->txt.imgwall3 = (int*)mlx_get_data_addr(e->txt.wall3, e->mlx.imgarg,
	e->mlx.imgarg + 1, e->mlx.imgarg + 2);
	e->txt.imgwall4 = (int*)mlx_get_data_addr(e->txt.wall4, e->mlx.imgarg,
	e->mlx.imgarg + 1, e->mlx.imgarg + 2);
	return (0);
}

void	put_txt_wall(t_env *e, t_pt_w ptw, int x, int y, int s_w, int h, t_vec v)
{
	double	xt;
	double	yt;

	if (s_w == 0)
		yt = detect_pxl_txt(e, ptw, v, s_w);
	else
		yt = s_w * TXT_L / h;
	if (ptw.w.n.x == 1)
	{
		xt = (ptw.p.y - (int)ptw.p.y) * TXT_L;
		if (ptw.w.m.y == ptw.w.ceil->m.y)
			e->mlx.img[y * DIMX + x] = e->txt.imgwall1[(int)(yt * TXT_L + xt)];
		else
			e->mlx.img[y * DIMX + x] = e->txt.imgwall3[(int)(yt * TXT_L + xt)];
	}
	else
	{
		xt = (ptw.p.x - (int)ptw.p.x) * TXT_L;
		if (ptw.w.m.x == ptw.w.ceil->m.x)
			e->mlx.img[y * DIMX + x] = e->txt.imgwall2[(int)(yt * TXT_L + xt)];
		else
			e->mlx.img[y * DIMX + x] = e->txt.imgwall4[(int)(yt * TXT_L + xt)];
	}
}

void	floor_casting(t_env *e, t_pt_w ptw, int x, int y)
{
	(void)ptw;
	e->mlx.img[y * DIMX + x] = 0x0022F5;
}
