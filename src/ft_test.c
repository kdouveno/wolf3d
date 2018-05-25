/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:03:15 by gperez            #+#    #+#             */
/*   Updated: 2018/05/25 16:28:24 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int    ft_test(t_env *e)
{
	t_base	*save;

	save = e->labstart;
	ft_putendl("qwer");
	while (save)
	{
		ft_putchar(save->obj.type);
		save = save->next;
	}
	return (0);
}
