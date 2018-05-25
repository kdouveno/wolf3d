/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:14:41 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:14:23 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		cmpt;

	cmpt = 0;
	if ((void*)src - dst < 0)
	{
		cmpt = len - 1;
		while (cmpt >= 0)
		{
			((char *)dst)[cmpt] = ((char *)src)[cmpt];
			cmpt--;
		}
		return (dst);
	}
	while (cmpt < (int)len)
	{
		((char *)dst)[cmpt] = ((char *)src)[cmpt];
		cmpt++;
	}
	return (dst);
}
