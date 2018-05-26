/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:15 by gperez            #+#    #+#             */
/*   Updated: 2018/05/26 17:52:41 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_test_next(t_env *e, int n)
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

// int    ft_test_iso(t_base *e, int nb_pos)
// {
// 	while (e){
// 		printf("n: (%d, %d, %d); m: (%d, %d, %d);\n\t",
// 		e->n.x, e->n.y, e->n.z,
// 		e->m.x, e->m.y, e->m.z,
// 		);
// 		e = e->next;
// 	}
// 	return (0);
// }

int		ft_test(t_env *e)
{
	t_base *save;

	save = e->labstart;
	ft_test_rec(save, 1);
	// ft_test_next(e, 1);
	return (0);
}
