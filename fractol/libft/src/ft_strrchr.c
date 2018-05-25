/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:44:17 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:20:07 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		cmpt;

	cmpt = ft_strlen(s);
	while (cmpt >= 0)
	{
		if (s[cmpt] == c)
			return ((char *)s + (cmpt));
		cmpt--;
	}
	return (NULL);
}
