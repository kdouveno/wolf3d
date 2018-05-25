/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:15:26 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:17:30 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char const *s1)
{
	int		cmpt;
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	cmpt = 0;
	while (s1[cmpt])
	{
		dst[cmpt] = s1[cmpt];
		cmpt++;
	}
	dst[cmpt] = '\0';
	return (dst);
}
