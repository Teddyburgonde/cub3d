/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/17 16:29:12 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_line_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' 
			&& str[i] != 'N'
			&&  str[i] != 'S'
			&&  str[i] != 'E'
			&&  str[i] != 'W'
			&&  str[i] != ' ')
			{
				return (0);
			}
		i++;
	}
	return (1);
}

int	parse_map(t_map_data *map_data)
{
	int	i;
	
	while (map_data->map[map_data->save] && is_full_whitespaces(map_data->map[map_data->save]) == 1)
		map_data->save++;
	while (map_data->map[map_data->save])
	{
		i = 0;
		if (is_line_valid(map_data->map[map_data->save]) == 0 || is_full_whitespaces(map_data->map[map_data->save]) == 1)
		{
			ft_putstr_fd(map_data->map[map_data->save], 2);
			ft_putstr_fd("Error: Invalid map\n", 2);
			return (1);
		}
		map_data->save++;
	}
	return (0);
}
