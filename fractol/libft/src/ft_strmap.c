/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:03:58 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:18:50 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		cmpt;
	char	*dst;

	if (s)
	{
		cmpt = 0;
		if ((dst = ft_strdup(s)) == NULL)
			return (NULL);
		while (s[cmpt])
		{
			dst[cmpt] = (*f)(s[cmpt]);
			cmpt++;
		}
		return (dst);
	}
	return (NULL);
}
