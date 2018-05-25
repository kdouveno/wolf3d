/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:12:38 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:51:58 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_puttab_int(int *tab, int taille, int space)
{
	int		cmpt;

	cmpt = 0;
	while (cmpt < taille)
	{
		ft_putnbr(tab[cmpt]);
		if (space == 1)
			ft_putchar('\n');
		cmpt++;
	}
}
