/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:16:14 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/13 14:35:26 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_north_south_textures(t_map *map, t_texture *texture, int i)
{
	char	**tab;

	tab = ft_split(map->map[i], ' ');
	if (tab[1] != NULL)
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
		{
			if ((texture->north_texture = mlx_load_png(tab[1])) == NULL)
			{
				ft_free(tab);
				return (1);
			}
		}
		else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
		{
			if ((texture->south_texture = mlx_load_png(tab[1])) == NULL)
			{
				ft_free(tab);
				return (1);
			}
		}
		ft_free(tab);
	}
	return (0);
}

int	load_west_east_textures(t_map *map, t_texture *texture, int i)
{
	char	**tab;

	tab = ft_split(map->map[i], ' ');
	if (tab[1] != NULL)
	{
		if (ft_strncmp(map->map[i], "WE ", 3) == 0)
		{
			if ((texture->west_texture = mlx_load_png(tab[1])) == NULL)
			{
				ft_free(tab);
				return (1);
			}
		}
		else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
		{
			if ((texture->east_texture = mlx_load_png(tab[1])) == NULL)
			{
				ft_free(tab);
				return (1);
			}
		}
		ft_free(tab);
	}
	return (0);
}
