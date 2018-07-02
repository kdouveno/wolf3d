#include "wolf3d.h"

int		txt(t_env *e)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
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

void	put_txt_wall(t_env *e, t_pt_v ptv, int x, int y, int s_w, int h)
{
	double	xt;
	double	yt;

	if (ptv.v.x == 1)
	{
		xt = (ptv.p.y - (int)ptv.p.y) * 64;
		yt = (y - s_w) * 64 / h;
		e->mlx.img[y * DIMX + x] = e->txt.imgwall1[(int)(yt * 64 + xt)];
	}
	else
	{
		xt = (ptv.p.x - (int)ptv.p.x) * 64;
		yt = (y - s_w) * 64 / h;
		e->mlx.img[y * DIMX + x] = e->txt.imgwall2[(int)(yt * 64 + xt)];
	}
}
