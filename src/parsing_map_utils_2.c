/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:50:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 14:35:21 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_first_and_last_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while (line && line[j])
	{
		if (line[j] != '1')
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_current_line(char *line, t_game *game)
{
	int	j;
	int	len;

	len = ft_strlen(line);
	j = 0;
	while (line && line[j])
	{
		if ((j == 0 || j == len - 1) && line[j] != '1')
		{
			ft_putstr_fd("Error: Invalid map\n", 2);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	get_lines_lenght(t_game *game)
{
	int	*lines_lenght;
	int	i;

	lines_lenght = malloc((game->data->nb_lines + 1) * sizeof(int));
	if (!lines_lenght)
	{
		free_structs(game);
		display_allocation_failed_and_exit();
	}
	i = 0;
	while (game->data->map[i])
	{
		lines_lenght[i] = ft_strlen(game->data->map[i]);
		i++;
	}
	lines_lenght[i] = -1;
	game->data->lines_lenght = lines_lenght;
}

static void	check_1_on_current_line(char **map, int i, \
t_game *game, int index)
{
	int	j;

	j = game->data->lines_lenght[index];
	while (j != -1 && map[i][j] && map[i][j] == '1')
		j++;
	if (j != -1 && map[i][j] && map[i][j] != '1')
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}

void	compare_lines_one_each_other(char **map, int i, \
t_game *game)
{
	int	lower_delta_len;
	int	upper_delta_len;
	int	*lines_lenght;

	lines_lenght = game->data->lines_lenght;
	lower_delta_len = lines_lenght[i] - lines_lenght[i - 1];
	upper_delta_len = lines_lenght[i] - lines_lenght[i + 1];
	if (lower_delta_len > 0)
		check_1_on_current_line(map, i, game, i - 1);
	if (upper_delta_len > 0)
		check_1_on_current_line(map, i, game, i + 1);
}
