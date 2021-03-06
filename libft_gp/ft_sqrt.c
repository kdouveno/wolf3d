/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:24:23 by gperez            #+#    #+#             */
/*   Updated: 2017/11/24 03:25:16 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sub_sqrt(int n, long cmpt)
{
	if ((cmpt * cmpt) < (long)n)
		return (ft_sub_sqrt(n, cmpt + 1));
	else if ((cmpt * cmpt) == (long)n)
		return (cmpt);
	else
		return (0);
}

int				ft_sqrt(int n)
{
	if (n <= 0)
		return (0);
	return (ft_sub_sqrt(n, 1));
}
