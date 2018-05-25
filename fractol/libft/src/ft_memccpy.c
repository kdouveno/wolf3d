/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:20:47 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:13:31 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cmpt;

	cmpt = 0;
	while (cmpt < n)
	{
		((char *)dst)[cmpt] = ((char *)src)[cmpt];
		if (((char *)src)[cmpt] == (char)c)
			return (dst + cmpt + 1);
		cmpt++;
	}
	return (NULL);
}
