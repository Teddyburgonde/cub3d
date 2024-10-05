/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/05 17:41:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_map_textures(t_map_data *map)
{
	int					i;
	t_counter_parameter	counter_parameter;

	i = 0;
	ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));//valider la fonction memset
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

int	ft_parse_map_path_texture(t_map_data *map, t_texture *texture)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0
			|| ft_strncmp(map->map[i], "SO ", 3) == 0)
		{
			if (load_north_south_textures(map, texture, i) != 0)
				return (message_error_return_1(
						"Error loading north or south texture\n"));  //free supplemetaires a prevoir
		}
		else if (ft_strncmp(map->map[i], "WE ", 3) == 0
			|| ft_strncmp(map->map[i], "EA ", 3) == 0)
		{
			if (load_west_east_textures(map, texture, i) != 0)
				return (message_error_return_1(
						"Error loading west or east texture\n")); //free supplemetaires a prevoir
		}
		i++;
	}
	return (0);
}

void	parsing_map_elements(t_game *game)
{
	if (ft_parse_map_textures(game->data) == 1)
	{
		ft_putstr_fd("Error: Wrong number of textures\n", 2);
		exit (1);
	}
	if (ft_parse_map_path_texture(game->data, game->texture) != 0)
	{
		ft_putstr_fd("Error: Wrong path of textures\n", 2);
		exit (1);
	}
	if (ft_parse_map_elements_colors(game->data) != 0)
	{
		ft_putstr_fd("Error: The colors are poorly defined\n", 2);
		exit (1);
	}
}
