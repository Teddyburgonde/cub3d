/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/10 17:41:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	ft_parse_map_elements(t_map *map)
{
	if (ft_strncmp(map->map[0], "NO ", 3) != 0 
	|| ft_strncmp(map->map[1], "SO ", 3) != 0 
	|| ft_strncmp(map->map[2], "WE ", 3) != 0
	|| ft_strncmp(map->map[3], "EA ", 3) != 0
	|| ft_strncmp(map->map[4], "F ", 2) != 0
	|| ft_strncmp(map->map[5], "C ", 2) != 0)
	{
		printf("Error: One or more elements are missing \n");
		return (1);	
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_map	map;

	if (parsing_arguments(argc, argv) == 1)
		return (1);
	if (check_and_open_file(&map, argv) == 1)
		return (1);
	init_texture(&map);
	map.map = get_map(map.fd);
	//ft_print_value_map(&map);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}



