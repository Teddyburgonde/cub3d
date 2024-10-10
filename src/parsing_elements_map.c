/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 18:12:09 by ppuivif          ###   ########.fr       */
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

static void	load_texture(char *map_line, mlx_texture_t **texture, \
t_game *game)
{
	char	**arr;

	arr = ft_split(map_line, ' ');
	if (map_line && !arr)
	{
		free_array(arr);
		free_structs(game);
		display_allocation_failed_and_exit();
	}
	if (arr[1])
		*texture = mlx_load_png(arr[1]);
	if (!arr[1] || !(*texture))
		handling_error_loading_texture(arr, game);
	free_array(arr);
}

static void	parse_map_path_texture(t_game *game)
{
	int			i;
	char		**map;
	
	i = 0;
	map = game->data->complete_map;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			load_texture(map[i], &game->texture->north_texture, game);
		if (ft_strncmp(map[i], "EA ", 3) == 0)
			load_texture(map[i], &game->texture->east_texture, game);
		if (ft_strncmp(map[i], "SO ", 3) == 0)
			load_texture(map[i], &game->texture->south_texture, game);
		if (ft_strncmp(map[i], "WE ", 3) == 0)
			load_texture(map[i], &game->texture->west_texture, game);
		i++;
	}
}

void	parsing_map_elements(t_game *game)
{
	parse_map_textures(game);
	parse_map_path_texture(game);
	if (ft_parse_map_elements_colors(game->data) != 0)
	{
		ft_putstr_fd("Error: The colors are poorly defined.\n", 2);
		exit (EXIT_FAILURE);
	}
}
