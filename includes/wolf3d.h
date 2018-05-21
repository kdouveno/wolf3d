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
	int				meta[2];
}					t_obj;

typedef struct			s_pos
{
	t_base		*cur;
	t_base		*s;
	t_base		*e;
	t_base		*l_l;
	t_base		*l;
	t_peer		*peer;
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
typedef struct			s_ctab
{
	int	cx;
	int	cy;
}						t_ctab;

typedef struct			s_params
{
	char				c;
	int					nbrparam;
}						t_params;

static const char		g_lab_chars[] = "o_s<>\\/dke ";
static const t_params	g_meta_chars[] = {
	{'P', 2},
	{'K', 1},
	{'D', 1},
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
void					error(t_env *e, char *msg);

#endif
