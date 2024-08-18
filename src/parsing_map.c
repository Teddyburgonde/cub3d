/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/18 18:15:17 by tebandam         ###   ########.fr       */
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

int	is_direction_valid(char *str, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (map_data->direction && (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'))
			return (0);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			map_data->direction = str[i];
		i++;
	}
	return (1);
}

static int	is_top_and_bottom_wall_closed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// is_top_wall_closed                           ok
// is_bottom_wall_closed                        ok
// is_left_wall_closed							ok
// is_right_wall_closed							OK


#include <stdio.h>
int	parse_map(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[map_data->save] && is_full_whitespaces(map_data->map[map_data->save]) == 1)
		map_data->save++;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (1);
	}
	while (map_data->map[map_data->save])
	{
		if (map_data->map[map_data->save][i] != '1')
		{
			printf("%c\n", map_data->map[map_data->save][i]);
			ft_putstr_fd("Error: Invalid map\n", 2);
			return (1);
		}
		j = ft_strlen(map_data->map[map_data->save]);
		j--;
		if (map_data->map[map_data->save][j] != '1')
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			return (1);
		}
		if (is_line_valid(map_data->map[map_data->save]) == 0 || is_full_whitespaces(map_data->map[map_data->save]) == 1)
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			return (1);
		}
		if (is_direction_valid(map_data->map[map_data->save], map_data) == 0)
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			return (1);
		}
		map_data->save++;
	}
	map_data->save--;
	if (is_top_and_bottom_wall_closed(map_data->map[map_data->save]) == 0)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (1);
	}
	if (!map_data->direction)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (1);
	}
	return (0);
}
