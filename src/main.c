/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 16:59:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_map_elements(t_map *map)
{
	int	i;
	t_counter_parameter counter_parameter;

	i = 0;
	ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
			counter_parameter.counter_no++;
		if (ft_strncmp(map->map[i], "SO ", 3) == 0)
			counter_parameter.counter_so++;
		if (ft_strncmp(map->map[i], "WE ", 3) == 0)
			counter_parameter.counter_we++;
		if (ft_strncmp(map->map[i], "EA ", 3) == 0)
			counter_parameter.counter_ea++;
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
			counter_parameter.counter_f++;
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
			counter_parameter.counter_c++;
		i++;
	}
	if (message_error_for_missing_elements(counter_parameter) == 1)
		return (1);
	return (0);
}


int ft_parse_map_path_texture(t_map *map)
{
	int	i;
	char **tab;

	i = 0;
	tab = ft_split(map->map[0], ' ');
	if ((!tab[0] || !tab[1]) || tab[2] != NULL)
	{
		ft_putstr_fd("Error elements for load image\n", 1);
		//ft_free(tab);
		return (1);
	}
	
}	




	
	
	
	
// 	// if (tab[1])
// 	// {
// 	// 	if (mlx_load_png(tab[1]) == NULL)
// 	// 		printf("Error loading texture\n");
// 	// 	else
// 	// 		printf("Image load ok\n");
// 	// }
// 	printf("%s\n", tab[0]);
// 	printf("%s\n", tab[1]);
// 	printf("%s\n", tab[2]);
// 	// ft_putstr_fd("\n", 1);
// 	// ft_putstr_fd("\n", 1);
// 	// while (i < 6)
// 	// {
// 	// 	if (tab[2] != NULL)
// 	// 	{
// 	// 		ft_putstr_fd(tab[2], 1);
// 	// 		ft_putstr_fd("\n", 1);
// 	// 	}
// 	// 	i++;
// 	// }
// 	return (0);
// }

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
	//ft_parse_map_path_texture(&map);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}
