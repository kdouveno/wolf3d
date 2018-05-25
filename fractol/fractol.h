/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:30:12 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 14:22:10 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <math.h>
# include <time.h>
# include <pthread.h>
# include "mlx.h"
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

# define W_HEIGHT 1000
# define W_WIDTH 1000
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define CYAN 0x00FFFF
# define BLUE 0x0000FF
# define PURPLE 0xFF00FF
# define WHITE 0xFFFFFF

# define NB_TH 500

# define PI 3.14159265359

typedef struct	s_window
{
	struct s_img	*img;
	struct s_coord	*coords;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*fractal;
	char			c;
	char			r;
	char			inter;
}				t_window;

typedef struct	s_img
{
	unsigned int	*img_s;
	int				bpp;
	int				size_line;
	int				endian;
}				t_img;

typedef struct	s_arg_thread
{
	int				th;
	int				i;
	int				cmpt;
	int				x;
	int				y;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	t_window		*win;
}				t_arg;

typedef struct	s_thread
{
	pthread_t		thread1;
}				t_thread;

typedef	struct	s_cmpt_tab
{
	int				cmpt_x;
	int				cmpt_y;
}				t_cmpt_tab;

typedef struct	s_complex
{
	double		r;
	double		im;
}				t_complex;

typedef union	u_color
{
	char			color_rgba[4];
	int				color;
}				t_color;

typedef struct	s_coord
{
	int					x;
	int					y;
	int					x_mouse;
	int					y_mouse;
	int					x_start;
	int					y_start;
	int					x_end;
	int					y_end;
	char				d;
	double				dir;
	double				ecart_x;
	double				ecart_y;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	t_complex			start;
	t_complex			reload;
	double				zoom;
	int					i;
	int					*pal_color;
	int					nbr_color;
}				t_coord;

void			fractol(char *fractal);
int				my_key(int key, t_window *win);
int				my_mouse(int button, int x, int y, t_window *win);
int				my_motion_mouse(int x, int y, t_window *win);
void			ft_draw(t_window *win);
int				ft_module(t_complex c);
void			ft_position(t_coord *coords, int x, int y);
void			ft_iteration(t_coord *coords, int x);
void			ft_split_color(t_coord coords, int i);
void			ft_move_image(t_window *win, char d);
int				ft_algo(t_window *win, t_complex inc, int i_max);
void			ft_interface(t_window *win, int color);
int				*ft_random_color(t_window *win);
void			*thread(void *arg);
void			ft_create_thread(t_thread th[NB_TH], t_arg arg[NB_TH]);

void			k_direction(int key, t_window *win);
void			k_refresh(t_window *win);
void			k_escape(t_window *win);
void			k_zoom(t_window *win, int key);
void			k_iter(t_window *win, int key);
void			k_coords(t_window *win, int key);
void			k_interface(t_window *win);
void			k_color(t_window *win);
void			k_lock(t_window *win);
#endif
