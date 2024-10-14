/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 19:58:10 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_map_validity(t_game *game)
{
	int		i;
	int		len;
	char	**map;
	int		flag;

	i = 0;
	len = 0;
	map = game->data->map;
	flag = 0;
	while (map[i])
	{
		check_if_empty_line(map[i], game);
		check_char_validity(map[i], game);
		get_player_initial_position_and_orientation(map[i], i, &flag, game);
		len = ft_strlen(map[i]);
		if(game->data->nb_columns < len)
			game->data->nb_columns = len;
		i++;
	}
	check_one_player(flag, game);
	game->data->nb_lines = i;
	check_if_map_closed(game);
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

static void	skip_first_empty_lines(char ***map)
{
	while (*map && line_is_full_whitespaces(*map[0]) == 1)
		(*map)++;
}

void	parsing_map(t_game *game)
{
	skip_first_empty_lines(&game->data->map);
	replace_spaces_with_walls(game->data->map);
	check_map_validity(game);
}
