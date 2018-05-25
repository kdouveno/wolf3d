/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:19:26 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:14:29 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cmpt;

	cmpt = 0;
	while (cmpt < len)
	{
		((char *)b)[cmpt] = (char)c;
		cmpt++;
	}
	return (b);
}
