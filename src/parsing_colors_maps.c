/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_maps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:07:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/16 09:26:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	get_color(int *color, char **tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(tab[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_putstr_fd("Error: Incorrect value\n", STDERR_FILENO);
			ft_free(tab);
			return (EXIT_FAILURE);
		}
		i++;
	}
	color[3] = ft_pixel(color[0], color[1], color[2]);
	return (EXIT_SUCCESS);
}

static int	ft_parse_color(char *map_line, int *color)
{
	char	**tmp;
	char	**tab;

	tmp = ft_split(map_line, ' ');
	if (!tmp)
		return (EXIT_FAILURE);
	tab = ft_split(tmp[1], ',');
	if (!tab)
	{
		ft_free(tmp);
		return (EXIT_FAILURE);
	}
	if (get_color(color, tab) == 1)
		return (EXIT_FAILURE);
	ft_free(tmp);
	ft_free(tab);
	return (EXIT_SUCCESS);
}

int	ft_parse_map_elements_colors(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
		{
			if (ft_parse_color(map->map[i], map->floor_color) == 1)
				return (EXIT_FAILURE);
		}
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
		{
			map->map_after_color = map->map[i + 2];
			if (ft_parse_color(map->map[i], map->ceiling_color) == 1)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
