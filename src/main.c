/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/16 16:50:13 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map		map;
	t_texture	texture;
	
	int	i;

	i = 0;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&texture, 0, sizeof(t_texture));
	if (check_and_open_file(&map, argv) == 1)
		return (EXIT_FAILURE);
	map.map = get_map(map.fd);
	if (ft_parse_map_elements(&map) == 1)
		return (EXIT_FAILURE);
	if (ft_parse_map_path_texture(&map, &texture) != 0)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements_colors(&map) != 0)
		return (EXIT_FAILURE);
	
	parse_map(&map);
	close(map.fd);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
