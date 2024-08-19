/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/19 15:04:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse_map(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[map_data->save] && is_full_whitespaces(map_data->map[map_data->save]) == 1)
		map_data->save++;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
		return (message_error_r1("Error: Invalid map\n"));
	while (map_data->map[map_data->save])
	{
		if (map_data->map[map_data->save][i] != '1' && map_data->map[map_data->save][i] != ' ')
			return (message_error_r1("Error: Invalid map\n"));
		j = ft_strlen(map_data->map[map_data->save]);
		j--;
		if (map_data->map[map_data->save][j] != '1')
			return (message_error_r1("Error: Invalid map\n"));
		if (is_line_valid(map_data->map[map_data->save]) == 0 || is_full_whitespaces(map_data->map[map_data->save]) == 1)
			return (message_error_r1("Error: Invalid map\n"));
		if (is_direction_valid(map_data->map[map_data->save], map_data) == 0)
			return (message_error_r1("Error: Invalid map\n"));
		map_data->save++;
	}
	map_data->save--;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
		return (message_error_r1("Error: Invalid map\n"));
	if (!map_data->direction)
		return (message_error_r1("Error: Invalid map\n"));
	return (0);
}
