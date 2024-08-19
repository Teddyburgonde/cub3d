/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/19 09:59:02 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_valid(char *str)
{
	char	*valid_chars;
	int	i;

	valid_chars = "10 NSEW";
	i = 0;
	while (str[i])
	{
		if (ft_strchr(valid_chars, str[i]) == 0)
			return (0);
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

int	is_top_and_bottom_wall_closed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}



