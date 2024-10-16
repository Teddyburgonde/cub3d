/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:23:56 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 20:05:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*static void	check_no_space_around_0(t_game *game)
{
	int		i;
	int		j;
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
}*/

# include <stdio.h>

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

static int	flood_fill_2(char **map, int x, int y, t_game *game)
{
	map[y][x] = 'c';
	if (y > 0 && x < ft_strlen(map[y - 1]) && (map[y - 1][x] == '0' || map[y - 1][x] == ' '))
		flood_fill_2(map, x, y - 1, game);
	else if (y > 0 && x < ft_strlen(map[y - 1]) && map[y - 1][x] != '1')
		return (1);
	if (x > 0 && y < game->data->nb_lines && (map[y][x - 1] == '0' || map[y][x - 1] == ' '))
		flood_fill_2(map, x - 1, y, game);
	else if (x > 0 && y < game->data->nb_lines && map[y][x - 1] != '1')
		return (1);
	if (y < game->data->nb_lines - 1 && x < ft_strlen(map[y + 1]) && (map[y + 1][x] == '0' || map[y + 1][x] == ' '))
		flood_fill_2(map, x, y + 1, game);
	else if (y < game->data->nb_lines - 1 && x < ft_strlen(map[y + 1]) && map[y + 1][x] != '1')
		return (1);
	if (x < ft_strlen(map[y]) - 1 && y < game->data->nb_lines && (map[y][x + 1] == '0' || map[y][x + 1] == ' '))
		flood_fill_2(map, x + 1, y, game);
	else if (x < ft_strlen(map[y]) - 1 && y < game->data->nb_lines && map[y][x + 1] != '1')
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
	return(map);
//	free_array(map);
}

void	ft_print_value_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("La valeur de map[] %s\n", map[i]);
		i++;
	}
}


void	check_if_0_closed_by_1(t_game *game, char **filled_map)
{
	int	i;
	int	j;
	
	j = 0;
	
//	printf("game->data->nb_lines : %d\n", game->data->nb_lines);
	
	while (filled_map && filled_map[j])
	{
		i = 0;
		while (filled_map[j][i])
		{	
			if (filled_map[j][i] == '0' && flood_fill_2(filled_map, i, j, game) == 1)
			{
				ft_putstr_fd("Error: Invalid map8\n", 2);
				free_array(filled_map);
				free_structs(game);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
	ft_print_value_map(filled_map);

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
//	check_if_map_closed(game);
	filled_map = check_no_reachable_space_from_player(game);
	check_if_0_closed_by_1(game, filled_map);
//	check_no_space_around_0(game);
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
