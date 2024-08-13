/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/13 17:59:20 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	ft_parse_map_elements_color(t_map *map)
{
	char	**tmp;
	char	**tab;
	int		i;
	
	i = 0;
	tmp = NULL;
	tab = NULL;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
		{
			tmp = ft_split(map->map[i], ' ');
			tab = ft_split(tmp[1], ',');
			map->floor_color = ft_atoi(tab[0]);
			if (map->floor_color >= 0 && map->floor_color <= 255)
				printf("La valeur %d est correct\n", map->floor_color);
			else
				printf("La valeur %d est incorrect\n", map->floor_color);
		}
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
		{
			ft_putstr_fd("ft_parse_map_elements_color C trouver 😊\n", 1);
		}
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_map		map;
	t_texture	texture;

	if (parsing_arguments(argc, argv) == 1)
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&texture, 0, sizeof(t_texture));
	if (check_and_open_file(&map, argv) == 1)
		return (1);
	map.map = get_map(map.fd);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	ft_parse_map_path_texture(&map, &texture);
	ft_parse_map_elements_color(&map);


	
	close(map.fd);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}
