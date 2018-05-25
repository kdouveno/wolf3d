/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:42:59 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:19:34 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t	cmpt;

	cmpt = 0;
	if (len == 0)
		return (dst);
	while (src[cmpt] && cmpt < len)
	{
		dst[cmpt] = src[cmpt];
		cmpt++;
	}
	if (cmpt < len)
	{
		while (cmpt < len)
		{
			dst[cmpt] = '\0';
			cmpt++;
		}
	}
	return (dst);
}
