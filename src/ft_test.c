/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:15 by gperez            #+#    #+#             */
/*   Updated: 2018/06/25 15:40:36 by kdouveno         ###   ########.fr       */
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

			ft_putnbr(save->m.x);
			ft_putchar(' ');
			ft_putnbr(save->m.y);
			ft_putchar(' ');
			ft_putnbr(save->m.z);
			ft_putstr("          ");
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
	if (e->xd != NULL && e->xd->obj.type == 'w')
		ft_putnbr(1);
	if (e->yu != NULL && e->yu->obj.type == 'w')
		ft_putnbr(2);
	if (e->xu != NULL && e->xu->obj.type == 'w')
		ft_putnbr(3);
	if (e->yd != NULL && e->yd->obj.type == 'w')
		ft_putnbr(4);
	if (e->next != NULL)
		ft_test_rec(e->next, nb_pos);
	return (0);
}

void	print_t_base(t_base *start)
{
	printf("%p | '%c' %3d %3d %3d | %3d %3d %3d | %d | %d %d | %d\n", start,
		start->obj.type, (int)start->m.x, (int)start->m.y, (int)start->m.z, (int)start->n.x, (int)start->n.y, (int)start->n.z, start->obj.dir, start->obj.meta[0], start->obj.meta[1], start->obj.cor);
	printf("\t/\\ %p", start->yu);
	if (start->yu)
		printf(" | '%c' %3d %3d %3d | %3d %3d %3d | %d | %d %d | %d\n",
		start->yu->obj.type, (int)start->yu->m.x, (int)start->yu->m.y, (int)start->yu->m.z, (int)start->yu->n.x, (int)start->yu->n.y, (int)start->yu->n.z, start->yu->obj.dir, start->yu->obj.meta[0], start->yu->obj.meta[1], start->yu->obj.cor);
	else
		printf("\n");
	printf("\t>> %p", start->xu);
	if (start->xu)
		printf(" | '%c' %3d %3d %3d | %3d %3d %3d | %d | %d %d | %d\n",
		start->xu->obj.type, (int)start->xu->m.x, (int)start->xu->m.y, (int)start->xu->m.z, (int)start->xu->n.x, (int)start->xu->n.y, (int)start->xu->n.z, start->xu->obj.dir, start->xu->obj.meta[0], start->xu->obj.meta[1], start->xu->obj.cor);
	else
		printf("\n");
	printf("\t\\/ %p", start->yd);
	if (start->yd)
		printf(" | '%c' %3d %3d %3d | %3d %3d %3d | %d | %d %d | %d\n",
		start->yd->obj.type, (int)start->yd->m.x, (int)start->yd->m.y, (int)start->yd->m.z, (int)start->yd->n.x, (int)start->yd->n.y, (int)start->yd->n.z, start->yd->obj.dir, start->yd->obj.meta[0], start->yd->obj.meta[1], start->yd->obj.cor);
	else
		printf("\n");
	printf("\t<< %p", start->xd);
	if (start->xd)
		printf(" | '%c' %3d %3d %3d | %3d %3d %3d | %d | %d %d | %d\n",
		start->xd->obj.type, (int)start->xd->m.x, (int)start->xd->m.y, (int)start->xd->m.z, (int)start->xd->n.x, (int)start->xd->n.y, (int)start->xd->n.z, start->xd->obj.dir, start->xd->obj.meta[0], start->xd->obj.meta[1], start->xd->obj.cor);
	else
		printf("\n");
}

void	ft_test_complet(t_env *e)
{
	t_base *start;

	start = e->labstart;
	while (start)
	{
		print_t_base(start);
		if (start->next && start->next->m.y != start->m.y)
			printf("\n");
		start = start->next;
	}
}

int		ft_test(t_env *e)
{
	t_base *save;

	save = e->labstart;
 	// ft_test_rec(save, 1);
	// ft_test_next(e, 1);
	ft_test_complet(e);
	return (0);
}
