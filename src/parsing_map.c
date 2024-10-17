/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/17 11:43:31 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	flood_fill(char **map, int x, int y, t_game *game)
{
	map[y][x] = '1';
	if (y > 0 && map[y - 1][x] == '0')
		flood_fill(map, x, y - 1, game);
	else if (y > 0 && map[y - 1][x] != '1')
		return (1);
	if (x > 0 && map[y][x - 1] == '0')
		flood_fill(map, x - 1, y, game);
	else if (x > 0 && map[y][x - 1] != '1')
		return (1);
	if (y < game->data->nb_lines - 1 && map[y + 1][x] == '0')
		flood_fill(map, x, y + 1, game);
	else if (y < game->data->nb_lines - 1 && map[y + 1][x] != '1')
		return (1);
	if (x < ft_strlen(map[y]) - 1 && map[y][x + 1] == '0')
		flood_fill(map, x + 1, y, game);
	else if (x < ft_strlen(map[y]) - 1 && map[y][x + 1] != '1')
		return (1);
	return (0);
}

static char	**check_no_reachable_space_from_player(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = arr_copy(game->data->map);
	x = game->player->player_pos_x;
	y = game->player->player_pos_y;
	if (flood_fill(map, x, y, game) == 1)
	{
		ft_putstr_fd("Error: Invalid map7\n", 2);
		free_array(map);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
	return (map);
}

static void	check_map_validity(t_game *game)
{
	int		i;
	int		len;
	char	**map;
	int		flag;
	char	**filled_map;

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
	filled_map = check_no_reachable_space_from_player(game);
	check_if_0_closed_by_1(game, filled_map);
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
