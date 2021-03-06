/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:19:56 by gperez            #+#    #+#             */
/*   Updated: 2017/11/19 13:58:47 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	int		nb_clone;
	int		div_dix;
	char	nb_conv;

	if (n < 0)
		ft_putchar('-');
	div_dix = 1;
	if (n > 0)
		n *= -1;
	nb_clone = n;
	while ((nb_clone / 10) < 0)
	{
		nb_clone /= 10;
		div_dix *= 10;
	}
	while (n > 0 || div_dix > 0)
	{
		nb_clone = n;
		nb_clone /= div_dix;
		nb_conv = -nb_clone + '0';
		ft_putchar(nb_conv);
		n %= div_dix;
		div_dix /= 10;
	}
}
