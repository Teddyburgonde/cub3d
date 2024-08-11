/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 11:11:07 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	ft_parse_map_elements(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
			map->counter_no++;
		if (ft_strncmp(map->map[i], "SO ", 3) == 0)
			map->counter_so++;
		if (ft_strncmp(map->map[i], "WE ", 3) == 0)
			map->counter_we++;
		if (ft_strncmp(map->map[i], "EA ", 3) == 0)
			map->counter_ea++;
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
			map->counter_f++;
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
			map->counter_c++;
		i++;
	}
	if (message_error_for_missing_elements(map) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (parsing_arguments(argc, argv) == 1)
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	if (check_and_open_file(&map, argv) == 1)
		return (1);
	//init_texture(&map);
	map.map = get_map(map.fd);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}
