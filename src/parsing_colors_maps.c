/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_maps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:07:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/08 07:57:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
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
			free_array(tab);
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
	if (!tmp && map_line)//to verify
		return (EXIT_FAILURE);//& free des structures
	tab = ft_split(tmp[1], ',');
	if (!tab && tmp[1])// to verify
	{
		free_array(tmp); //& free des structures
		return (EXIT_FAILURE);
	}
	if (get_color(color, tab) == 1)
		return (EXIT_FAILURE);//& free des structures//&free structures
	free_array(tmp);
	free_array(tab);
	return (EXIT_SUCCESS);
}

int	ft_parse_map_elements_colors(t_map_data *map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
		{
			if (ft_parse_color(map->map[i], map->floor_color) == 1)
				return (EXIT_FAILURE);//&free structures
		}
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
		{
			map->save = i + 1;
			if (ft_parse_color(map->map[i], map->ceiling_color) == 1)
				return (EXIT_FAILURE);//&free structures
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
