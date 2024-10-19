/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 22:26:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	flood_fill_from_player(char **map, int x, int y, t_game *game)
{
	int	len;

	len = game->data->nb_lines;
	map[y][x] = '1';
	if (y > 0 && x < ft_strlen(map[y - 1]) && \
	(map[y - 1][x] == '0'))
		flood_fill_from_player(map, x, y - 1, game);
	else if (y == 0 || (y > 0 && x < ft_strlen(map[y - 1]) && \
	map[y - 1][x] != '1') || (y > 0 && x >= ft_strlen(map[y - 1])))
		exit_when_space_reachable_by_player(map, game);
	if (x > 0 && y < len && map[y][x - 1] == '0')
		flood_fill_from_player(map, x - 1, y, game);
	else if (x == 0 || (x > 0 && y < len && map[y][x - 1] != '1'))
		exit_when_space_reachable_by_player(map, game);
	if (y < len - 1 && x < ft_strlen(map[y + 1]) && map[y + 1][x] == '0')
		flood_fill_from_player(map, x, y + 1, game);
	else if (y == len - 1 || (y < len - 1 && \
	x < ft_strlen(map[y + 1]) && map[y + 1][x] != '1') ||
	(y < game->data->nb_lines - 1 && x >= ft_strlen(map[y + 1])))
		exit_when_space_reachable_by_player(map, game);
	if (x < ft_strlen(map[y]) - 1 && y < len && map[y][x + 1] == '0')
		flood_fill_from_player(map, x + 1, y, game);
	else if (x == ft_strlen(map[y]) - 1 || (x < ft_strlen(map[y]) - 1 && \
	y < len && map[y][x + 1] != '1'))
		exit_when_space_reachable_by_player(map, game);
}

static char	**check_no_reachable_space_from_player(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = arr_copy(game->data->map);
	if (game->data->map && game->data->map[0] && !map)
	{
		free_structs(game);
		display_allocation_failed_and_exit(0);
	}
	x = game->player->player_pos_x;
	y = game->player->player_pos_y;
	flood_fill_from_player(map, x, y, game);
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
