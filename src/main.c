/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 10:09:20 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	ft_parse_map_elements(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * 7);
	if (!map->map)
		ft_putstr_fd("Error allocation\n", 1);
	map->map[0] = ft_strdup("NO texture_north");
	map->map[1] = ft_strdup("SO texture_south");
	map->map[2] = ft_strdup("WE texture_west");
	map->map[3] = ft_strdup("EA texture_east");
	map->map[4] = ft_strdup("F floor_color");
	map->map[5] = ft_strdup("C ceiling_color");
	map->map[6] = NULL;
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
	if (map->counter_no != 1 || map->counter_so != 1 || map->counter_we != 1 
		|| map->counter_ea != 1 || map->counter_f != 1 || map->counter_c != 1)
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
	initialize_map(&map);
	//init_texture(&map);
	map.map = get_map(map.fd);
	//ft_print_map_elements(&map);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}



