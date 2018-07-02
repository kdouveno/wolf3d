/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:36:29 by kdouveno          #+#    #+#             */
/*   Updated: 2018/06/25 16:26:16 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WALL_SIZE
# define CHAR_SIZE
# include "msgs.h"
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
//# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"
# include "../../minilibx/mlx.h"
# include "/usr/include/X11/X.h"
# define DIMX 750
# define DIMY 750
# define NBR_PARAM_MAX 2
# define FOV 66
# define ROT 5
# define MOV 0.1
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

/*
**	3D PART
*/

typedef struct			s_3d
{
	double					x;
	double					y;
	double					z;
}						t_3d;

typedef t_3d			t_vec;
typedef t_3d			t_pt;

typedef struct			s_pt_v
{
	t_pt				p;
	t_vec				v;
}						t_pt_v;

/*
**	Wolf3d Labyrinth shape storage
**
**	'k': key (doorId)
**	'd': door (doorId)
**	'p': portal ()
**	'f': fake Wall3
*/

typedef enum			e_metadir
{
	CENTER, UP, RIGHT, DOWN, LEFT, UP_LEFT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT
}						t_metadir;

typedef struct			s_obj
{
	char				type;
	t_metadir			dir;
	int					meta[NBR_PARAM_MAX];
	int					cor;
}						t_obj;

typedef struct			s_base
{
	t_vec				n;
	t_pt				m;
	t_obj				obj;
	int					lcd[64];
	struct s_base		*xu;
	struct s_base		*xd;
	struct s_base		*yu;
	struct s_base		*yd;
	struct s_base		*ceil;
	struct s_base		*next;
}						t_base;

typedef struct			s_cam
{
	t_3d				p;
	double				fov;
	double				dist;
	t_vec				dir;
	t_vec				v_u;
	t_vec				move;
	t_base				*cur;
}						t_cam;

typedef struct			s_peer
{
	t_base				*base;
	int					id;
	struct s_peer		*next;
}						t_peer;

typedef struct			s_pos
{
	t_base				*cur;
	t_base				*s;
	t_base				*e;
	t_base				*l_l;
	t_base				*l;
	t_peer				*peer;
	int					tabi;
	int					x;
	int					y;
}						t_pos;

/*
**	Miscellenous
*/


typedef struct			s_ctab
{
	int	cx;
	int	cy;
}						t_ctab;

typedef struct			s_params
{
	char				c;
	int					has_dir;
	int					nbrparam;
	char				match;
}						t_params;

typedef struct			s_text
{
	void				*wall1;
	void				*wall2;
	void				*wall3;
	void				*wall4;

	int					*imgwall1;
	int					*imgwall2;
	int					*imgwall3;
	int					*imgwall4;
	int					imgarg[3];
}						t_text;

static const t_params	g_meta_chars[] = {
	{'o', 0, 0, '\0'},
	{'p', 1, 2, 'p'},
	{'k', 0, 1, 'd'},
	{'d', 1, 1, 'k'},
	{'e', 0, 0, 's'},
	{'s', 0, 0, 'e'},
	{'_', 0, 0, '\0'},
	{' ', 0, 0, '\0'},
	{'\0', 0, 0, '\0'}
};


/*
**	Global Environment
*/
typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	void				*imgptr;
	int					*img;
	int					imgarg[3];
}						t_mlx;

typedef struct			s_env
{
	t_mlx				mlx;
	t_base				*labstart;
	t_cam				cam;
	t_text				txt;
}						t_env;

void					parse(t_env *e, char *path);
int						check_line(char *line);
int						check_meta(char *line, int i);
void					add_base(t_env *e, t_pos *pos, char **tab, char c);

int						ft_test(t_env *e);
void					error(t_env *e, char *msg);

t_base					*add_wall(t_env *e, t_base *base);
void					wall_left(t_env *e, t_pos *pos);
void					wall_up(t_env *e, t_pos *pos);
void					finish(t_env *e, t_pos *pos);
void					check_peer(t_env *e, t_pos *pos);
int						txt(t_env *e);
void					put_txt_wall(t_env *e, t_pt_v ptv, int x, int y, int s_w, int h);

void					algo(t_env *e);
t_pt_v					scan(t_env *e, t_vec v);

int 					my_key(int key, t_env *e);
t_base					**get_base(t_base *base, t_metadir dir);

t_vec					ft_norm_vec(t_vec v);
t_pt					apply(t_vec v, t_pt p);
t_vec					vecpro(t_vec v, double a);

double					rad(double deg);
t_vec					ft_rotate_z(t_vec v, double teta);
t_vec					ft_neg_vec(t_vec v);

t_base					**get_base(t_base *b, t_metadir d);

#endif
