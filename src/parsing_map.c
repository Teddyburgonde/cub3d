/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/25 15:15:00 by ppuivif          ###   ########.fr       */
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

int	parse_map(t_map_data *map_data)
{
	while (map_data->map[map_data->save]
		&& is_full_whitespaces(map_data->map[map_data->save]) == 1)
		map_data->save++;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	while (map_data->map[map_data->save])
	{
		if (check_around_0(map_data->map) == 1)
			return (message_error_return_1("Error: Invalid map\n"));
		if (is_validate_map_line(map_data->map[map_data->save], map_data) != 0)
			return (1);
		map_data->save++;
	}
	map_data->save--;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
		return (message_error_return_1("Error: Invalid map\n"));
	if (!map_data->direction)
		return (message_error_return_1("Error: Invalid map\n"));
	return (0);
}
