/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_path_textures.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 20:11:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	handling_error_loading_texture(char **arr, t_game *game)
{
	ft_putstr_fd("Error loading ", 2);
	ft_putstr_fd(arr[0], 2);
	ft_putstr_fd(" texture\n", 2);
	free_array(arr);
	free_structs(game);
	exit(EXIT_FAILURE);
}

static void	load_texture(char *line, mlx_texture_t **texture, \
t_game *game)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (line && !arr)
	{
		free_array(arr);
		free_structs(game);
		display_allocation_failed_and_exit(0);
	}
	if (arr[1])
		*texture = mlx_load_png(arr[1]);
	if (!arr[1] || !(*texture))
		handling_error_loading_texture(arr, game);
	free_array(arr);
}

void	parsing_file_path_textures(t_game *game)
{
	int			i;
	char		*tmp;

	i = 0;
	while (game->data->file_content[i])
	{
		tmp = skip_first_spaces(game->data->file_content[i]);
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			load_texture(tmp, &game->texture->north_texture, game);
		if (ft_strncmp(tmp, "EA ", 3) == 0)
			load_texture(tmp, &game->texture->east_texture, game);
		if (ft_strncmp(tmp, "SO ", 3) == 0)
			load_texture(tmp, &game->texture->south_texture, game);
		if (ft_strncmp(tmp, "WE ", 3) == 0)
			load_texture(tmp, &game->texture->west_texture, game);
		i++;
	}
}
