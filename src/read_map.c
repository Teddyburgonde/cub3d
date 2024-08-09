/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:16:35 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/09 02:18:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	read_map(t_map *map, char **line)
{
	*line = get_next_line(map->fd);
	if (!*line)
	{
		ft_putstr_fd("Error: During reading.\n", 2);
		return (1);
	}
	return (0);
}
