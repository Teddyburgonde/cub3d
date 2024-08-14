/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/15 00:28:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>


// Etudier , RGBA 
// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

int	get_color(int *floor_color, char **tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		floor_color[i] = ft_atoi(tab[i]);
		if (!floor_color[i] || floor_color[i] < 0 || floor_color[i] > 255)
		{
			printf("Error: Incorrect value\n");
			ft_free(tab);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_parse_floor_color(char *map_line, int *floor_color)
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
	if (get_color(floor_color, tab) == 1)
		return (EXIT_FAILURE);
	ft_free(tmp);
	ft_free(tab);
	return (EXIT_SUCCESS);
}

int	ft_parse_map_elements_color(t_map *map)
{
	int		i;
	map->floor_color = ft_calloc(3, sizeof(int));
	if (!map->floor_color)
		return (1);
	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
		{
			if (ft_parse_floor_color(map->map[i], map->floor_color) == 1)
				return (1);
		}
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
		{
			ft_putstr_fd("ft_parse_map_elements_color C trouver 😊\n", 1);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	t_map		map;
	t_texture	texture;

	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&texture, 0, sizeof(t_texture));
	if (check_and_open_file(&map, argv) == 1)
		return (EXIT_FAILURE);
	map.map = get_map(map.fd);
	if (ft_parse_map_elements(&map) == 1)
		return (EXIT_FAILURE);
	ft_parse_map_path_texture(&map, &texture);
	ft_parse_map_elements_color(&map);


	
	close(map.fd);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
