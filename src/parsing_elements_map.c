/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 14:59:13 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	handling_error_loading_texture(char **tab, char **map)
{
	ft_putstr_fd("Error loading ", 2);
	ft_putstr_fd(tab[0], 2);
	ft_putstr_fd(" texture\n", 2);
	free_array(tab);
	free_array(map);
	exit(EXIT_FAILURE);
}

static void	load_texture(char **map, char *map_line, mlx_texture_t *texture)
{
	char	**tab;

	tab = ft_split(map_line, ' ');
	if (map_line && !tab)
	{
		free_array(map);
		display_allocation_failed_and_exit();
	}
	if (tab[1])
		texture = mlx_load_png(tab[1]);
	if (!tab[1] || !texture)
		handling_error_loading_texture(tab, map);
	free_array(tab);
}

/*static int	load_north_south_textures(char **map, char *texture_line, t_texture *texture)
{
	char	**tab;

	tab = ft_split(texture_line, ' ');
	if (texture_line && !tab)
	{
		free_array(map);
		display_allocation_failed_and_exit();
	}
	if (tab[1] != NULL)
	{
		if (ft_strncmp(tab[0], "NO", 2) == 0)
		{
			texture->north_texture = mlx_load_png(tab[1]);
			if (!texture->north_texture)
				return (1);
		}
		else if (ft_strncmp(tab[0], "SO", 2) == 0)
		{
			texture->south_texture = mlx_load_png(tab[1]);
			if (!texture->south_texture)
				return (1);
		}
		free_array(tab);
	}
	else
		return (1);
	return (0);
}*/

//static int	load_west_east_textures(char **map, char *texture_line, t_texture *texture, int i)
/*int	load_west_east_textures(t_map_data *map_data, t_texture *texture, int i)
{
	char	**tab;

	tab = ft_split(map_data->map[i], ' ');
	if (!tab[1] && map_data->map[i])
		display_allocation_failed_and_exit();// to verify
	if (tab[1] != NULL)
	{
		if (ft_strncmp(tab[0], "WE", 2) == 0)
		{
			texture->west_texture = mlx_load_png(tab[1]);
			if (!texture->west_texture)
				return (1);
		}
		else if (ft_strncmp(tab[0], "EA", 2) == 0)
		{
			texture->east_texture = mlx_load_png(tab[1]);
			if (!texture->east_texture)
				return (1);
		}
		free_array(tab);
	}
	else
		return (1);
	return (0);
}*/

/*static int	parse_map_path_texture(char **map, t_texture *textures)
//static int	parse_map_path_texture(t_map_data *map, t_texture *texture)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0
			|| ft_strncmp(map[i], "SO ", 3) == 0)
		{
			if (load_north_south_textures(map, &map[i], textures) != 0)
				return (message_error_return_1(
						"Error loading north or south texture\n"));  //free supplemetaires a prevoir
		}
		else if (ft_strncmp(map[i], "WE ", 3) == 0
			|| ft_strncmp(map[i], "EA ", 3) == 0)
		{
			if (load_west_east_textures(&map[i], textures) != 0)
				return (message_error_return_1(
						"Error loading west or east texture\n")); //free supplemetaires a prevoir
		}
		i++;
	}
	return (0);
}*/

static void	parse_map_path_texture(char **map, t_texture *textures)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			load_texture(map, map[i], textures->north_texture);
		if (ft_strncmp(map[i], "EA ", 3) == 0)
			load_texture(map, map[i], textures->east_texture);
		if (ft_strncmp(map[i], "SO ", 3) == 0)
			load_texture(map, map[i], textures->south_texture);
		if (ft_strncmp(map[i], "WE ", 3) == 0)
			load_texture(map, map[i], textures->west_texture);
		i++;
	}
}

void	parsing_map_elements(char **map, t_texture *textures, t_game *game)
{
//	if (parse_map_textures(game->data) == 1)
	parse_map_textures(map);
	parse_map_path_texture(map, textures);
/*	if (parse_map_path_texture(game->data, game->texture) != 0)
	{
		ft_putstr_fd("Error: Wrong path of textures\n", 2);
		exit (EXIT_FAILURE);
	}*/
	if (ft_parse_map_elements_colors(game->data) != 0)
	{
		ft_putstr_fd("Error: The colors are poorly defined.\n", 2);
		exit (EXIT_FAILURE);
	}
}
