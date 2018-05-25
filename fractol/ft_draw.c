/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:47:00 by gperez            #+#    #+#             */
/*   Updated: 2018/05/10 10:46:00 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move(t_window *win, t_arg arg[NB_TH], t_thread th[NB_TH])
{
	arg[0].x = win->coords->x_start;
	arg[0].x_start = win->coords->x_start;
	arg[0].y = win->coords->y_start;
	arg[0].x_end = win->coords->x_end;
	arg[0].y_end = win->coords->y_end;
	if (pthread_create(&th[0].thread1, NULL, thread, &arg[0]) == -1)
		ft_putendl("Error creating thread1 !");
	if (pthread_join(th[0].thread1, NULL))
		ft_putendl("Error joining thread1!");
}

static void	init(t_window *win, t_arg arg[NB_TH], int *cmpt)
{
	while (*cmpt < NB_TH)
	{
		arg[*cmpt].th = *cmpt + 1;
		arg[*cmpt].win = win;
		arg[*cmpt].cmpt = win->coords->nbr_color;
		(*cmpt)++;
	}
	win->coords->x = win->coords->x_start;
	win->coords->y = win->coords->y_start;
	*cmpt = 0;
}

static void	ft_start_end(t_window *win, t_arg arg[NB_TH], int *cmpt, int *cmp_x)
{
	if (*cmpt == 0 || *cmpt == NB_TH / 2)
	{
		arg[*cmpt].x = win->coords->x_start;
		arg[*cmpt].x_start = win->coords->x_start;
		arg[*cmpt].y = win->coords->y_start;
		arg[*cmpt].x_end = win->coords->x_end / (NB_TH / 2);
		if (*cmpt == NB_TH / 2)
			arg[*cmpt].y_end = win->coords->y_end;
		else
			arg[*cmpt].y_end = win->coords->y_end / 2;
	}
	else
	{
		arg[*cmpt].x = win->coords->x_end / (NB_TH / 2) * *cmp_x;
		arg[*cmpt].x_start = win->coords->x_end / (NB_TH / 2) * *cmp_x;
		arg[*cmpt].y = win->coords->y_end / 2;
		arg[*cmpt].x_end = win->coords->x_end;
		arg[*cmpt].y_end = win->coords->y_end;
	}
}

static void	ft_mid(t_window *win, t_arg arg[NB_TH], int *cmpt, int *cmpt_x)
{
	if (*cmpt < (NB_TH / 2))
	{
		arg[*cmpt].x = win->coords->x_end / (NB_TH / 2) * *cmpt;
		arg[*cmpt].x_start = win->coords->x_end / (NB_TH / 2) * *cmpt;
		arg[*cmpt].x_end = win->coords->x_end / (NB_TH / 2) * (*cmpt + 1);
		arg[*cmpt].y = win->coords->y_start;
		arg[*cmpt].y_end = win->coords->y_end / 2;
	}
	else
	{
		arg[*cmpt].x = win->coords->x_end / (NB_TH / 2) * *cmpt_x;
		arg[*cmpt].x_start = win->coords->x_end / (NB_TH / 2) * *cmpt_x;
		arg[*cmpt].x_end = win->coords->x_end / (NB_TH / 2) * (*cmpt_x + 1);
		arg[*cmpt].y = win->coords->y_end / 2;
		arg[*cmpt].y_end = win->coords->y_end;
		(*cmpt_x)++;
	}
}

void		ft_draw(t_window *win)
{
	t_arg		arg[NB_TH];
	t_thread	th[NB_TH];
	int			cmpt;
	int			cmpt_x;

	cmpt = 0;
	cmpt_x = 1;
	init(win, arg, &cmpt);
	if (win->coords->d == 0)
	{
		while (cmpt < NB_TH)
		{
			if (cmpt == 0 || cmpt == NB_TH / 2 || cmpt == NB_TH - 1)
				ft_start_end(win, arg, &cmpt, &cmpt_x);
			else
				ft_mid(win, arg, &cmpt, &cmpt_x);
			cmpt++;
		}
		ft_create_thread(th, arg);
	}
	else
		ft_move(win, arg, th);
}
