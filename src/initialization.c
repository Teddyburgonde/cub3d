/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:30:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 09:38:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// void init_texture(t_map *map)
// {
// 	ft_memset(&(map->textures), 0, sizeof(map->textures));
// }

void initialize_map(t_map *map)
{
	map->fd = -1;
	map->map = NULL;
	map->weight = 0;
	map->height = 0;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->counter_no = 0;
	map->counter_so = 0;
	map->counter_we = 0;
	map->counter_ea = 0;
	map->counter_f = 0; 
	map->counter_c = 0; 
}
