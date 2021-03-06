/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:45:34 by gperez            #+#    #+#             */
/*   Updated: 2017/11/19 15:28:24 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int		cmpt;

	cmpt = 0;
	while (s1[cmpt])
	{
		if (s1[cmpt] != s2[cmpt])
			return (((unsigned char *)s1)[cmpt] - ((unsigned char *)s2)[cmpt]);
		cmpt++;
	}
	return (((unsigned char *)s1)[cmpt] - ((unsigned char *)s2)[cmpt]);
}
