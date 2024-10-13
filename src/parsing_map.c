/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/13 10:01:42 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_one_player(int flag, t_game *game)
{
	if(flag != 1)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		free_structs(game);
		exit(EXIT_FAILURE);
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
		len = ft_strlen(map[i];)
		check_char_validity(map[i], len, game);
		get_player_initial_position_and_orientation(map[i], i, &flag, game);

		check_around_0(map, game); //flood_fill?

		i++;
	}
	check_one_player(flag, game)
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

static void	skip_first_empty_lines(char **map)
{
	while (map && is_full_whitespaces(map[0]) == 1)
		map++;
}

void	parsing_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	skip_first_empty_lines(game->data->map) //faut-il envoyer l'adresse ?
	map = game->data->map;
	replace_spaces_with_walls(map);
//	check_map_validity(map, game);

	
	check_top_and_bottom_wall_closed(map[0], game);

	while (map[i])
	{
		check_around_0(map, game);
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
