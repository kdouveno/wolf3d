/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:59:58 by gperez            #+#    #+#             */
/*   Updated: 2017/11/23 14:36:01 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		lng;
	int		cmpt;

	if (s)
	{
		lng = ft_strlen(s);
		cmpt = 0;
		while (cmpt < lng)
		{
			s[cmpt] = '\0';
			cmpt++;
		}
	}
}
