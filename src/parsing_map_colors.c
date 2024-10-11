/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 09:07:59 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/11 10:56:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	get_color(int *color, char **arr, t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(arr[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_putstr_fd("Error: Incorrect color value\n", 2);
			free_array(arr);
			free_structs(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	color[3] = ft_pixel(color[0], color[1], color[2]);
}

static void	parsing_color(char *line, int *color, t_game *game)
{
	char	**tmp;
	char	**arr;

	tmp = ft_split(line, ' ');
	if (line && !tmp)
	{
		free_structs(game);
		display_allocation_failed_and_exit();
	}
	arr = ft_split(tmp[1], ',');
	if (tmp[1] && !arr)
	{
		free_array(tmp);
		free_structs(game);
		display_allocation_failed_and_exit();
	}
	free_array(tmp);
	get_color(color, arr, game);
	free_array(arr);
}

void	parsing_file_colors(t_game *game)
{
	int		i;
	char	**content;

	i = 0;
	content = game->data->file_content;
	while (content[i])
	{
		if (ft_strncmp(content[i], "F ", 2) == 0)
			parsing_color(content[i], game->data->floor_color, game);
		if (ft_strncmp(content[i], "C ", 2) == 0)
		{
//			game->data->save = i + 1;
			parsing_color(content[i], game->data->ceiling_color, game);
		}
		i++;
	}
}
