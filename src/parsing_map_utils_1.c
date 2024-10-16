/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 09:37:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_if_empty_line(char *line, t_game *game)
{
	if(line && line_is_full_whitespaces(line) == 1)
	{
		ft_putstr_fd("Error: Invalid map1\n", 2);
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
			ft_putstr_fd("Error: Invalid map2\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_if_map_closed(t_game *game)
{
	int		i;
	char	**map;
	int *lines_len;

	i = 0;
	map = game->data->map;
	check_first_and_last_line(map[i], game);
	i++;
	lines_len = get_lines_lenght(game);
	while(map[i] && i < game->data->nb_lines - 1)
	{
		compare_lines_one_each_other(map, i, game, lines_len);
		check_current_line(map[i], game, lines_len);
		i++;
	}
	free(lines_len);
	check_first_and_last_line(map[i], game);
}
