/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:07:28 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:17:14 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	int		cmpt;

	cmpt = 0;
	while (src[cmpt] != '\0')
	{
		dst[cmpt] = src[cmpt];
		cmpt++;
	}
	dst[cmpt] = '\0';
	return (dst);
}
