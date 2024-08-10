/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/10 20:52:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	ft_parse_map_elements(t_map *map)
{
	int	i;

	i = 0;
	printf("ft_parse_map_element before while\n");
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
	printf("ft_parse_map_element after while\n");
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
	initialization_all_struct(&map);
	init_texture(&map);
	map.map = get_map(map.fd);
	printf("main apres get_map\n");
	//ft_print_map_elements(&map);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}



