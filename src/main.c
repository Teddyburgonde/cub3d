/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/13 14:14:05 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rayresult castRay(t_player player, float rayAngle, int map[MAP_HEIGHT][MAP_WIDTH]) 
{
    float x = player.x;
    float y = player.y;
    float dx = cos(rayAngle);
    float dy = sin(rayAngle);

    // Incrémenter x et y jusqu'à ce qu'on touche un mur
    int i = 0;
    while (map[(int)floor(y)][(int)floor(x)] == 0) 
	{
        x += dx * 0.1;
        y += dy * 0.1;
        i++;
        if (i > 400) break;  // Éviter les boucles infinies
    }

    float distance = sqrtf((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y));
    float wallHeight = 300.0f / distance;

    t_rayresult result;
    result.distance = distance;
    result.wallHeight = wallHeight;
    return (result);
}






int	main(int argc, char **argv)
{
	t_texture				texture;
	t_map_data				map;
	int						i;

	i = 0;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	ft_memset(&map, 0, sizeof(t_map_data));
	ft_memset(&texture, 0, sizeof(t_texture));
	if (check_and_open_file(&map, argv) == 1)
		return (EXIT_FAILURE);
	map.map = get_map(map.fd);
	if (!map.map)
		return (EXIT_FAILURE);
	//ft_print_value_map(&map);
	if (ft_parse_map_elements(&map) == 1)
		return (EXIT_FAILURE);
	if (ft_parse_map_path_texture(&map, &texture) != 0)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements_colors(&map) != 0)
		return (EXIT_FAILURE);
	parse_map(&map);
}












	
	// close(map.fd);
	// ft_free(map.map);
	// ft_delete_texture(texture);
	// ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	//return (EXIT_SUCCESS);
