/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:38:47 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:51:34 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_puttab_s(char **tab, int space)
{
	int		cmpt;

	cmpt = 0;
	while (tab[cmpt] != NULL)
	{
		if (space == 1)
			ft_putendl(tab[cmpt]);
		else
			ft_putstr(tab[cmpt]);
		cmpt++;
	}
}
