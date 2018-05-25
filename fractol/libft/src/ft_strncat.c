/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:39:52 by gperez            #+#    #+#             */
/*   Updated: 2018/02/26 14:19:08 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	int		cmpt_s1;
	int		cmpt_s2;

	cmpt_s1 = 0;
	cmpt_s2 = 0;
	while (s1[cmpt_s1])
		cmpt_s1++;
	while (s2[cmpt_s2] && cmpt_s2 < (int)n)
	{
		s1[cmpt_s1] = s2[cmpt_s2];
		cmpt_s1++;
		cmpt_s2++;
	}
	s1[cmpt_s1] = '\0';
	return (s1);
}