/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/11 11:00:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_validate_map_line(char *line, t_map_data *map_data)
{
	int	j;

	if (line[0] != '1' && line[0] != ' ')
		return (message_error_return_1("Error: Invalid map\n"));
	j = ft_strlen(line) - 1;
	if (line[j] != '1')
		return (message_error_return_1("Error: Invalid map\n"));
	if (is_line_valid(line) == 0 || is_full_whitespaces(line) == 1)
		return (message_error_return_1("Error: Invalid map\n"));
	if (is_direction_valid(line, map_data) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	return (0);
}

static void	replace_spaces_with_walls(char	**map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j + 1])
	{
		i = 1;
		while (map[j][i + 1])
		{
			if (map[j][i] == 32)
				map[j][i] = '1';
			i++;
		}
		j++;
	}
}

int	parsing_map(t_game *game)
{
	char	**map;
	int		i;
//	int		save;

	map = game->data->map;
	i = 0;
	//	save = game->data->save;
	while (map && is_full_whitespaces(map[0]) == 1)
		map++;
	replace_spaces_with_walls(map);
	if (is_top_and_bottom_wall_closed(map[0]) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	while (map[i])
	{
		if (check_around_0(map) == 1)
			return (message_error_return_1("Error: Invalid map\n"));
		if (is_validate_map_line(map[i], game->data) != 0)
			return (1);
		i++;
	}
	i--;
	if (is_top_and_bottom_wall_closed(map[i]) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	if (!game->data->direction)
		return (message_error_return_1("Error: Invalid map\n"));
	return (0);
}
