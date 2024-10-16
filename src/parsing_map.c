/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 12:08:53 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_no_space_around_0(t_game *game)
{
	int	i;
	int	j;
	char	**map;

	j = 1;
	map = game->data->map;
	while (map[j + 1])
	{
		i = 1;
		while (i < ft_strlen(map[j]) - 1)
		{
			if (map[j][i] == '0')
			{
				if (map[j - 1][i] == ' ' || map[j + 1][i] == ' ' || \
					map[j][i - 1] == ' ' || map[j][i + 1] == ' ')
				{
					ft_putstr_fd("Error: Invalid map\n", 2);
					free_structs(game);
					exit(EXIT_FAILURE);
				}
			}
			i++;
		}
		j++;
	}
}

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
		if (game->data->nb_columns < len)
			game->data->nb_columns = len;
		i++;
	}
	check_one_player(flag, game);
	game->data->nb_lines = i;
	check_if_map_closed(game);
	check_no_space_around_0(game);
}

static void	skip_first_empty_lines(char ***map)
{
	while (*map && **map && ***map == 0)
		(*map)++;
}

void	parsing_map(t_game *game)
{
	skip_first_empty_lines(&game->data->map);
	check_map_validity(game);
}
