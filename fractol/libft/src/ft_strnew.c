/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:07:00 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:19:48 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	int		cmpt;
	char	*s;

	cmpt = 0;
	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (cmpt <= (int)size)
	{
		s[cmpt] = '\0';
		cmpt++;
	}
	return (s);
}
