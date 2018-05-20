/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:36:29 by kdouveno          #+#    #+#             */
/*   Updated: 2018/05/20 14:56:20 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WALL_SIZE
# define CHAR_SIZE

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
typedef struct		s_obj
{
	char			type;
	int				meta;
}					t_obj;

typedef struct		s_base
{
	t_vec			n;
	t_pt			m;
	t_obj			obj;
	int				lcd[64];
	struct s_base	*xu;
	struct s_base	*xd;
	struct s_base	*yu;
	struct s_base	*yd;
	struct s_base	*ceil;
	struct s_base	*next;

}					t_base;

/*
**	Miscellenous
*/
typedef struct		s_ctab
{
	int	cx;
	int	cy;
}					t_ctab;

static const char	g_lab_chars[] = "o_s<>\\/dke ";
static const char	g_meta_chars[] = {

}

/*
**	Global Environment
*/
typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*imgptr;
	int				*img;
	int				imgarg[3];
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	t_base			*lab;
}					t_env;

void				parser(t_env *env);

#endif
