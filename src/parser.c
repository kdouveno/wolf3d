/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:56 by gperez            #+#    #+#             */
/*   Updated: 2018/05/20 15:00:23 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	check_meta(char *line, int cmpt)
{
	int cmpt_m;

	cmpt_m = 0;
	while (line[cmpt] != '\0')
	{
		/*while (line[cmpt] != g_meta_chars[cmpt_m] && line[cmpt] != '\0')
			cmpt_m++;
		if (line[cmpt] == '\0')
			return (0);
		else
			error(ERROR_FILE);*/
	}
}



int		check_line(char *line)
{
	int	cmpt;

	cmpt = 0;
	while (line[cmpt] != '|' && line[cmpt] != '\0')
		if (!(line[cmpt] == 'o' || line[cmpt] == '_' || line[cmpt] == 's'
		|| line[cmpt] == '<' || line[cmpt] == '>' || line[cmpt] == '\\'
		|| line[cmpt] == '/' || line[cmpt] == 'd' || line[cmpt] == 'k'
		|| line[cmpt] == 'e' || line[cmpt] == ' '))
			error(ERROR_FILE);
		cmpt++;
	if (check_meta(line, cmpt) == 1)
		error(ERROR_FILE);
	return (0);
}

void	parse_line(t_env *e, char *labline, char **)
{

}

int		parser(t_env *e, char *path)
{
	char	*line;
	int		fd;
	char	**pipe;
	char	**params;

	if (open())
	while (get_next_line(fd, &line) >= 1)
	{
		if (check_line(line) == 1)
			return (1);

		parse_line(e, line);
		free(line);
	}
	return (0);
}
