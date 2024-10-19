/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:07:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 20:12:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	exit_when_incorrect_color_value(char **arr, t_game *game)
{
	ft_putstr_fd("Error: Incorrect color value\n", 2);
	free_array(arr);
	free_structs(game);
	exit(EXIT_FAILURE);
}

static void	get_color(int *color, char **arr, t_game *game)
{
	int	i;

	i = 0;
	while (arr[i] && i < 3)
	{
		color[i] = ft_atoi(arr[i]);
		if (color[i] < 0 || color[i] > 255)
			exit_when_incorrect_color_value(arr, game);
		i++;
	}
	if (color[0] && color[1] && color[2])
		color[3] = ft_pixel(color[0], color[1], color[2]);
	else
		exit_when_incorrect_color_value(arr, game);
}

static void	parsing_color(char *line, int *color, t_game *game)
{
	char	**arr;

	arr = ft_split(&line[1], ',');
	if (!arr)
	{
		free_structs(game);
		display_allocation_failed_and_exit(0);
	}
	get_color(color, arr, game);
	free_array(arr);
}

void	parsing_file_colors(t_game *game)
{
	int		i;
	char	**content;
	char	*tmp;

	i = 0;
	content = game->data->file_content;
	while (content[i])
	{
		tmp = skip_first_spaces(content[i]);
		if (ft_strncmp(tmp, "F ", 2) == 0)
			parsing_color(tmp, game->data->floor_color, game);
		if (ft_strncmp(tmp, "C ", 2) == 0)
		{
			game->data->begin_map_index = i + 1;
			parsing_color(tmp, game->data->ceiling_color, game);
		}
		i++;
	}
}
