/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:15 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 20:28:59 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int   ft_test_next(t_env *e, int n)
{
	t_base	*save;
	int		nb_pos;

	nb_pos = 0;
	save = e->labstart;
	while (save)
	{
		if (nb_pos != save->m.y)
			ft_putchar('\n');
		ft_putchar(save->obj.type);
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
		}
		save = save->next;
	}
	return (0);
}

/*int    ft_test_rec(t_base *e, int nb_pos)
{
	t_base	*newxu;
	t_base	*newxd;
	t_base	*newyu;
	t_base	*newyd;

	if (nb_pos != e->m.y)
		ft_putchar('\n');
	ft_putchar(e->obj.type);
	nb_pos = e->m.y;
	newxu = e->xu;
	newxd = e->xd;
	newyu = e->yu;
	newyd = e->yd;
	if (newxd != NULL)
		ft_putnbr(1);
	if (newyu != NULL)
		ft_putnbr(2);
	if (newxu != NULL)
		ft_putnbr(3);
	if (newyd != NULL)
		ft_putnbr(4);
	if (e->next != NULL)
		ft_test_rec(e->next, nb_pos);
	return (0);
}*/

int    ft_test(t_env *e)
{
	t_base *save;

	save = e->labstart;
	//ft_test_rec(save, 0);
	ft_test_next(e, 1);
	return (0);
}
