/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:56 by gperez            #+#    #+#             */
/*   Updated: 2018/06/25 16:18:30 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_meta(char *line, int i)
{
	while (line[i] != '\0' && (ft_isdigit(line[i]) || line[i] == ' '))
		i++;
	return (line[i] != '\0');
}

int			check_line(char *line)
{
	int	i;
	int i_l;

	i = 0;
	while (line[i] != '|' && line[i] != '\0')
	{
		i_l = 0;
		while (line[i] != g_meta_chars[i_l].c && g_meta_chars[i_l].c)
			i_l++;
		if (g_meta_chars[i_l].c == '\0')
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	return (line[i] == '|' ? check_meta(line, i + 1) : 0);
}

void		parse_line(t_env *e, t_pos *pos, char *lab, char **tab)
{
	int i;

	if (lab)
	{
		i = 0;
		pos->x = 1;
		while (lab[i])
		{
			if (lab[i] != ' ')
			{
				if (lab[i] != '_')
					add_base(e, pos, tab, lab[i]);
				pos->x++;
			}
			i++;
		}
		pos->y++;
	}
	ft_free_tab(tab);
}

void		parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		check;
	char	**tab;
	t_pos	pos;

	pos = (t_pos){NULL, NULL, NULL, NULL, NULL, NULL, 0, 1, 1};
	if ((fd = open(path, O_RDONLY)) == -1)
		error(e, OPEN_ERROR);
	while ((check = get_next_line(fd, &line)) >= 1)
	{
		if (*line && check_line(line))
			error(e, FILE_ERROR);
		tab = ft_strsplit(line, '|');
		pos.tabi = 0;
		parse_line(e, &pos, tab[0], (tab[0] != NULL && tab[1] != NULL
			? ft_strsplit(tab[1], ' ') : NULL));
		free(line);
	}
	finish(e, &pos);
	if (check == -1)
		error(e, READ_ERROR);
	if (close(fd) == -1)
		error(e, CLOSE_ERROR);
}
