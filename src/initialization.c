/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:30:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 01:34:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	initialization_map_struct(t_map *map)
{
	ft_memset(map, 0, sizeof(*map));
}

void	initialization_all_struct(t_map *map)
{
	initialization_map_struct(map);
}
