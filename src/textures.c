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
	e->txt.imgwall1 = (int*)mlx_get_data_addr(e->txt.wall1, e->txt.imgarg,
	e->txt.imgarg + 1, e->txt.imgarg + 2);

	e->txt.imgwall2 = (int*)mlx_get_data_addr(e->txt.wall2, e->txt.imgarg,
	e->txt.imgarg + 1, e->txt.imgarg + 2);

	e->txt.imgwall3 = (int*)mlx_get_data_addr(e->txt.wall3, e->txt.imgarg,
	e->txt.imgarg + 1, e->txt.imgarg + 2);

	e->txt.imgwall4 = (int*)mlx_get_data_addr(e->txt.wall4, e->txt.imgarg,
	e->txt.imgarg + 1, e->txt.imgarg + 2);
	return (0);
}

void	put_txt_wall(t_env *e, t_pt_v ptv, int x, int y, int s_w, int h)
{
	double	xt;
	double	yt;

	(void)h;
	(void)s_w;
	(void)ptv;
	(void)yt;

//	printf("ptv : %f %f %f\n",ptv.v.x, ptv.v.y, ptv.v.z);

	if (ptv.v.x == 1)
	{
		xt = (ptv.p.y - (int)ptv.p.y) * 64;
		yt = (y - s_w) * 64 / h;
		e->mlx.img[y * DIMX + x] = e->txt.imgwall1[(int)roundf(yt * 64 + xt)];
	}
	else
	{
		//e->mlx.img[y * DIMX + x] = 0xFFFFFF;
		xt = (ptv.p.x - (int)ptv.p.x) * 64;
		yt = (y - s_w) * 64 / h;
		e->mlx.img[y * DIMX + x] = e->txt.imgwall2[(int)roundf(yt * 64 + xt)];
		/*xt = (ptv.p.x - (int)ptv.p.x) * 64;
		yt = (y - s_w) * 64 / h;
		n =  yt * xt;
		e->mlx.img[y * DIMX + x] = e->txt.imgwall4[n];*/
	}
}
