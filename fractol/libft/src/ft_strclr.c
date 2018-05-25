/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:59:58 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:16:57 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
