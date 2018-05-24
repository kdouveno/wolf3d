/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:36:29 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/21 18:06:03 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WALL_SIZE
# define CHAR_SIZE
# include "msgs.h"
# include "libft.h"
# include "mlx.h"
# define DIMX 1600
# define DIMY 900
# define PRES 10000
# define NBR_PARAM_MAX 2
# include <fcntl.h>

# include <stdio.h>

/*
**	3D PART
*/

typedef struct		s_3d
{
	int	x;
	int	y;
	int	z;
}					t_3d;

typedef t_3d		t_vec;
typedef t_3d		t_pt;

/*
**	Wolf3d Labyrinth shape storage
**
**	'k': key (doorId)
**	'd': door (doorId)
**	'p': portal ()
**	'f': fake Wall3
*/

typedef struct		s_peer
{
	char			type;
	int				a;
	int				b;
	int				id;
	struct s_peer 	*next;
}					t_peer;

typedef struct		s_obj
{
	char			type;
	metadir			dir;
	int				meta[NBR_PARAM_MAX];
}					t_obj;

typedef struct			s_pos
{
	t_base		*cur;
	t_base		*s;
	t_base		*e;
	t_base		*l_l;
	t_base		*l;
	t_peer		*peer;
	int			tabi;
	int			x;
	int			y;
}						t_pos;

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

/*
**	Miscellenous
*/

typedef enum metadir
{
	CENTER, UP, RIGHT, DOWN, LEFT
};

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
}						t_params;

static const t_params	g_meta_chars[] = {
	{'o', 0, 0},
	{'p', 1, 2},
	{'k', 0, 1},
	{'d', 1, 1},
	{'e', 0, 0},
	{'s', 0, 0},
	{'_', 0, 0},
	{' ', 0, 0},
	{'\0', 0}
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
}						t_env;

void					parse(t_env *e, char *path);
int						check_line(char *line);
int						check_meta(char *line, int i);
void 					add_base(t_env *e, t_pos *pos, char **tab, char c);
void					error(t_env *e, char *msg);

#endif
