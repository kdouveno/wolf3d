/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:50:32 by gperez            #+#    #+#             */
/*   Updated: 2018/05/10 13:19:15 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create_thread(t_thread th[NB_TH], t_arg arg[NB_TH])
{
	int	cmpt;

	cmpt = 0;
	while (cmpt < NB_TH)
	{
		if (pthread_create(&th[cmpt].thread1, NULL, thread, &arg[cmpt]) == -1)
		{
			ft_putstr("Error creating thread");
		}
		cmpt++;
	}
	cmpt = 0;
	while (cmpt < NB_TH)
	{
		if (pthread_join(th[cmpt].thread1, NULL))
			ft_putendl("Error joining thread!");
		cmpt++;
	}
}
