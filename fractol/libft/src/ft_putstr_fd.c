/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:12:43 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:15:55 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	cmpt;

	if (s)
	{
		cmpt = 0;
		while (s[cmpt])
		{
			ft_putchar_fd(s[cmpt], fd);
			cmpt++;
		}
	}
}
