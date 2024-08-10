/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:30:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/10 20:49:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void initialization_all_struct(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
}

void init_texture(t_map *map)
{
	ft_memset(&(map->textures), 0, sizeof(map->textures));
}
