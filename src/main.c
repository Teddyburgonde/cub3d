/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/12 18:59:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// code generer a etudier 


/*
int	load_texture(char *map_line, const char *prefix, void **texture_ptr)
{
	char	**tab;

	if (ft_strncmp(map_line, prefix, 3) == 0)
	{
		tab = ft_split(map_line, ' ');
		if (tab[1] != NULL)
		{
			if (mlx_load_png(tab[1]) == NULL)
			{
				printf("Error loading texture\n");
				ft_free(tab);
				return (1);
			}
			else
				*texture_ptr = mlx_load_png(tab[1]);
			ft_free(tab);
		}
	}
	return (0);
}

int	ft_parse_map_path_texture(t_map *map, t_texture *texture)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (load_texture(map->map[i], "NO ", (void**)&texture->north_texture) ||
			load_texture(map->map[i], "SO ", (void**)&texture->south_texture) ||
			load_texture(map->map[i], "WE ", (void**)&texture->west_texture) ||
			load_texture(map->map[i], "EA ", (void**)&texture->east_texture))
		{
			return (1);
		}
		i++;
	}
	ft_putstr_fd("All textures are OK", 1);
	return (0);
}


*/


int	ft_parse_map_elements(t_map *map)
{
	int	i;
	t_counter_parameter counter_parameter;

	i = 0;
	ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
			counter_parameter.counter_no++;
		if (ft_strncmp(map->map[i], "SO ", 3) == 0)
			counter_parameter.counter_so++;
		if (ft_strncmp(map->map[i], "WE ", 3) == 0)
			counter_parameter.counter_we++;
		if (ft_strncmp(map->map[i], "EA ", 3) == 0)
			counter_parameter.counter_ea++;
		if (ft_strncmp(map->map[i], "F ", 2) == 0)
			counter_parameter.counter_f++;
		if (ft_strncmp(map->map[i], "C ", 2) == 0)
			counter_parameter.counter_c++;
		i++;
	}
	if (message_error_for_missing_elements(counter_parameter) == 1)
		return (1);
	return (0);
}

#include <stdio.h>

int	ft_parse_map_path_texture(t_map *map, t_texture *texture)
{
	int	i;
	char	**tab;

	i = 0;
	tab = NULL;
	while (map->map[i])
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
		{
			tab = ft_split(map->map[i], ' ');
			if (tab[1] != NULL)
			{
				if (mlx_load_png(tab[1]) == NULL)
				{
 					printf("Error loading texture\n");
					ft_free(tab);
					return (1);
				}
				else
				 	texture->north_texture = mlx_load_png(tab[1]);
				ft_free(tab);
			}
		}
		else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
		{
			tab = ft_split(map->map[i], ' ');
			if (tab[1] != NULL)
			{
				if (mlx_load_png(tab[1]) == NULL)
				{
 					printf("Error loading texture\n");
					ft_free(tab);
					return (1);
				}
				else
				 	texture->south_texture = mlx_load_png(tab[1]);
				ft_free(tab);
			}
		}
		else if (ft_strncmp(map->map[i], "WE ", 3) == 0)
		{
			tab = ft_split(map->map[i], ' ');
			if (tab[1] != NULL)
			{
				if (mlx_load_png(tab[1]) == NULL)
				{
 					printf("Error loading texture\n");
					ft_free(tab);
					return (1);
				}
				else
				 	texture->west_texture = mlx_load_png(tab[1]);
				ft_free(tab);
			}
		}
		else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
		{
			tab = ft_split(map->map[i], ' ');
			if (tab[1] != NULL)
			{
				if (mlx_load_png(tab[1]) == NULL)
				{
 					printf("Error loading texture\n");
					ft_free(tab);
					return (1);
				}
				else
				 	texture->east_texture = mlx_load_png(tab[1]);
				ft_free(tab);
			}
		}
		i++;
	}
	ft_putstr_fd("All texture it's OK", 1);
	return (0);
}


// telecharger les autres textures	

int	main(int argc, char **argv)
{
	t_map	map;
	t_texture texture;

	if (parsing_arguments(argc, argv) == 1)
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&texture, 0, sizeof(t_texture));
	if (check_and_open_file(&map, argv) == 1)
		return (1);
	map.map = get_map(map.fd);
	if (ft_parse_map_elements(&map) == 1)
		return (1);
	ft_parse_map_path_texture(&map, &texture);
	//ft_parse_map_path_texture(&map);
	close(map.fd);
	ft_putstr_fd("Parsing ok all elements exist 😊\n", 1);
	// //? free_map(map);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (0);
}
