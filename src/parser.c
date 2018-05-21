/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <gperez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:57:56 by gperez            #+#    #+#             */
/*   Updated: 2018/05/21 17:32:42 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_meta(char *line, int i)
{
	int i_m;
	int last;

	last = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		i_m = 0;
		while (last == 0 && line[i] != g_meta_chars[i_m].c
			&& g_meta_chars[i_m].c)
			i_m++;
		if (g_meta_chars[i_m].c == '\0')
			return (1);
		else if (last == 0)
			last = g_meta_chars[i_m].nbrparam;
		else if (ft_isdigit(line[i]) && !ft_isdigit(line[i + 1]))
			last--;
		else if (!ft_isdigit(line[i]))
			return (1);
		i++;
	}
	return (last > 0);
}

int			check_line(char *line)
{
	int	i;
	int i_l;

	i = 0;
	while (line[i] != '|' && line[i] != '\0')
	{
		i_l = 0;
		while (line[i] != g_lab_chars[i_l] && g_lab_chars[i_l])
			i_l++;
		if (g_lab_chars[i_l] == '\0')
			return (1);
		i++;
	}
	return (line[i] == '|' ? check_meta(line, i + 1) : 0);
}

void	parse_line(t_env *e, t_last *last, char *lab, char **tab)
{
	last.x = 0;
	while (lab[i])
	{
		if (lab[i] != ' ')
		{
			add_base(e, last, tab[i]);
			last->l = e->lab->
		}
		last.x++;
	}
	last.y++;
	ft_free_tab(tab);
}

void		parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		check;
	char	**tab;
	t_last	last;

	last = {NULL, NULL, NULL, NULL, NULL};
	if ((fd = open(path, O_RDONLY)) == -1)
		error(e, OPEN_ERROR);
	while ((check = get_next_line(fd, &line)) >= 1)
	{
		if (check_line(line))
			error(e, FILE_ERROR);
		tab = ft_strsplit(line, '|');
		parse_line(e, tab[0], (!tab[0] && !tab[1] ? ft_strsplit(tab[1], ' ')
		: NULL), &last);
		free(line);
	}
	if (check == -1)
		error(e, READ_ERROR);
	if (close(fd) == -1)
		error(e, CLOSE_ERROR);
}
