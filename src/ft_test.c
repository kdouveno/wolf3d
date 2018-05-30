/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:15 by gperez            #+#    #+#             */
/*   Updated: 2018/05/30 14:31:47 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_test_next(t_env *e, int n)
{
	t_base	*save;
	int		nb_pos;
	int     i;

	nb_pos = 0;
	save = e->labstart;
	while (save)
	{
		if (nb_pos != save->m.y)
			ft_putchar('\n');
		ft_putchar(save->obj.type);
		ft_putchar(' ');
		nb_pos = save->m.y;
		if (n == 1)
		{

			ft_putchar('\n');
			ft_putnbr(save->m.x);
			ft_putchar(' ');
			ft_putnbr(save->m.y);
			ft_putchar(' ');
			ft_putnbr(save->m.z);
			ft_putchar('\n');
			/*
			ft_putstr("dir: ");
			ft_putnbr(save->obj.dir);
			ft_putchar(' ');
			ft_putstr("meta: ");*/
			i = 0;
			while (i < NBR_PARAM_MAX)
			{
				ft_putnbr(save->obj.meta[i]);
				ft_putchar(' ');
				i++;
			}
			ft_putstr("cor: ");
			ft_putnbr(save->obj.cor);
			ft_putchar('\n');
		}
		save = save->next;
	}
	return (0);
}

int    ft_test_rec(t_base *e, int nb_pos)
{
	if (nb_pos != e->m.y)
		ft_putchar('\n');
	ft_putchar(e->obj.type);
	nb_pos = e->m.y;
	if (e->xd != NULL && e->xd->n.z == 0)
		ft_putnbr(1);
	if (e->yu != NULL && e->yu->n.z == 0)
		ft_putnbr(2);
	if (e->xu != NULL && e->xu->n.z == 0)
		ft_putnbr(3);
	if (e->yd != NULL && e->yd->n.z == 0)
		ft_putnbr(4);
	if (e->next != NULL)
		ft_test_rec(e->next, nb_pos);
	return (0);
}

int		ft_test(t_env *e)
{
	t_base *save;

	save = e->labstart;
	//ft_test_rec(save, 1);
 	ft_test_next(e, 1);
	return (0);
}
