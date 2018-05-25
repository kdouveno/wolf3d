/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:32:02 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:17:57 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		cmpt;

	if (s && (*f) != NULL)
	{
		cmpt = 0;
		while (s[cmpt])
		{
			(*f)((unsigned int)cmpt, s + cmpt);
			cmpt++;
		}
	}
}
