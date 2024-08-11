/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:09:49 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 11:09:52 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void	ft_print_value_map(t_map *map)
{
	printf("La valeur de map[0] %s\n", map->map[0]);
	printf("La valeur de map[1] %s\n", map->map[1]);
	printf("La valeur de map[2] %s\n", map->map[2]);
}

int	ft_print_map_elements(t_map *map)
{
	if (ft_strncmp(map->map[0], "NO ", 3) == 0)
		printf("Finded NO\n");
	if (ft_strncmp(map->map[1], "SO ", 3) == 0)
		printf("Finded SO\n");
	if (ft_strncmp(map->map[2], "WE ", 3) == 0)
		printf("Finded WE\n");
	if (ft_strncmp(map->map[3], "EA ", 3) == 0)
		printf("Finded EA\n");
	if (ft_strncmp(map->map[4], "F ", 2) == 0)
		printf("Finded F\n");
	if (ft_strncmp(map->map[5], "C ", 2) == 0)
		printf("Finded C\n");
	else
	{
		printf("Error: One or more elements are missing \n");
		return (1);
	}
	return (0);
}
