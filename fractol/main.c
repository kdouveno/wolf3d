/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:44:52 by gperez            #+#    #+#             */
/*   Updated: 2018/05/13 18:34:52 by gperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	filter(void)
{
	if (W_WIDTH != W_HEIGHT)
	{
		ft_putendl("Error: Lenght not equal.");
		return (1);
	}
	if (W_WIDTH < 162)
	{
		ft_putendl("Error: Length too small.");
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	*fractal;

	if (filter() == 1)
		return (0);
	if (argc == 2)
	{
		fractal = ft_str_tolower(argv[1]);
		if (ft_strcmp(fractal, "mandel") == 0 ||
				ft_strcmp(fractal, "julia") == 0 ||
				ft_strcmp(fractal, "boat") == 0 ||
				ft_strcmp(fractal, "julia_boat") == 0)
			fractol(fractal);
		else
		{
			ft_putendl("\aIllegal parameter's name.\nUsage: "
					"Mandel, Julia, Boat, Julia_Boat.");
			free(fractal);
		}
	}
	else
		ft_putendl("\aIllegal parameter's number.\nUsage: "
				"Mandel, Julia, Boat, Julia_Boat.");
	return (0);
}
