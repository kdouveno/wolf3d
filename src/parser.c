/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:56 by gperez            #+#    #+#             */
/*   Updated: 2018/05/17 14:21:27 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_line(char *line)
{
	int	cmpt;

	cmpt = 0;
	while (line[cmpt] == 'o' || line[cmpt] == '_' || line[cmpt] == 's'
		|| line[cmpt] == '<' || line[cmpt] == '>' || line[cmpt] == '\\'
		|| line[cmpt] == '/' || line[cmpt] == 'd' || line[cmpt] == 'k')
		{
			cmpt++;
		}
}

void	parse_line(t_env *e, char *labline, char **)
{

}

void	parser(t_env *e, char *path)
{
	char	*line;
	int		fd;
	char	**pipe;
	char	**params;

	if (open())
	while (get_next_line(fd, &line) >= 1)
	{
		check_line(line);
		parse_line(e, );
		free(line);
	}
}
