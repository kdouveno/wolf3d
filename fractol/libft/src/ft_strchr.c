/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:31:55 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:16:49 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char const *s, int c)
{
	int		cmpt;

	cmpt = 0;
	while (s[cmpt])
	{
		if (s[cmpt] == c)
			return ((char *)s + cmpt);
		cmpt++;
	}
	if (c == '\0')
		return ((char *)s + cmpt);
	return (NULL);
}
