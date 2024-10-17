/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/17 17:09:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_if_empty_line(char *line, t_game *game)
{
	if (line && *line == 0)
	{
		ft_putstr_fd("Error: Invalid map (empty line)\n", 2);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}

void	check_char_validity(char *line, t_game *game)
{
	int		j;
	char	*valid_chars;

	j = 0;
	valid_chars = "10 NSEW";
	while (line && line[j])
	{
		if (ft_strchr(valid_chars, line[j]) == 0)
		{
			ft_putstr_fd("Error: Invalid map (invalid char)\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

static void	flood_fill_from_0(char **map, int x, int y, t_game *game)
{
	map[y][x] = 'c';
	if (y > 0 && x < ft_strlen(map[y - 1]) && \
	(map[y - 1][x] == '0' || map[y - 1][x] == ' '))
		flood_fill_from_0(map, x, y - 1, game);
	else if (y == 0 || (y > 0 && x < ft_strlen(map[y - 1]) && \
	map[y - 1][x] != '1' && map[y - 1][x] != 'c'))
		exit_when_0_non_closed_by_1(map, game);
	if (x > 0 && y < game->data->nb_lines && \
	(map[y][x - 1] == '0' || map[y][x - 1] == ' '))
		flood_fill_from_0(map, x - 1, y, game);
	else if (x == 0 || (x > 0 && y < game->data->nb_lines && \
	map[y][x - 1] != '1' && map[y][x - 1] != 'c'))
		exit_when_0_non_closed_by_1(map, game);
	if (y < game->data->nb_lines - 1 && x < ft_strlen(map[y + 1]) && \
	(map[y + 1][x] == '0' || map[y + 1][x] == ' '))
		flood_fill_from_0(map, x, y + 1, game);
	else if (y == game->data->nb_lines - 1 || (y < game->data->nb_lines - 1 && \
	x < ft_strlen(map[y + 1]) && map[y + 1][x] != '1' && map[y + 1][x] != 'c'))
		exit_when_0_non_closed_by_1(map, game);
	if (x < ft_strlen(map[y]) - 1 && y < game->data->nb_lines && \
	(map[y][x + 1] == '0' || map[y][x + 1] == ' '))
		flood_fill_from_0(map, x + 1, y, game);
	else if (x == ft_strlen(map[y]) - 1 || (x < ft_strlen(map[y]) - 1 && \
	y < game->data->nb_lines && map[y][x + 1] != '1' && map[y][x + 1] != 'c'))
		exit_when_0_non_closed_by_1(map, game);
}

void	check_if_0_closed_by_1(t_game *game, char **filled_map)
{
	int	i;
	int	j;

	j = 0;
	while (filled_map && filled_map[j])
	{
		i = 0;
		while (filled_map[j][i])
		{
			if (filled_map[j][i] == '0')
			{
				flood_fill_from_0(filled_map, i, j, game);
			}
			i++;
		}
		j++;
	}
	free_array(filled_map);
}
