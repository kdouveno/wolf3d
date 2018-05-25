/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:38:51 by gperez            #+#    #+#             */
/*   Updated: 2018/04/12 11:06:28 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_pow(double n, int p)
{
	double	resultat;

	resultat = 1;
	if (p <= 0)
		return (1);
	while (p >= 1)
	{
		resultat *= n;
		p--;
	}
	return (resultat);
}
