/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:26:58 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/11 16:53:46 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int	ft_parse_map_elements_color(t_map *map)
// {
// 	int	i;
// 	// int	counter_no;
// 	// int	counter_so;
// 	// int	counter_we;
// 	// int	counter_ea;

// 	// counter_no = 0;
// 	// counter_so = 0;
// 	// counter_we = 0;
// 	// counter_ea = 0;
// 	int	counter_f;
// 	int	counter_c;

// 	counter_c = 0;
// 	counter_f = 0;
// 	i = 0;
// 	while (map->map[i])
// 	{
// 		// if (ft_strncmp(map->map[i], "NO ", 3) == 0)
// 		// 	counter_no++;
// 		// else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
// 		// 	counter_so++;
// 		// else if (ft_strncmp(map->map[i], "WE ", 3) == 0)
// 		// 	counter_we++;
// 		// else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
// 		// 	counter_ea++;
// 		if (ft_strncmp(map->map[i], "F ", 2) == 0)
// 			counter_f++;
// 		if (ft_strncmp(map->map[i], "C ", 2) == 0)
// 			counter_c++;
// 		i++;
// 	}
// 	if (message_error_for_missing_elements_color(map) == 1)
// 		return (1);
// 	return (0);
// }

// int	ft_parse_map_elements_wall(t_map *map)
// {
// 	int	i;
// 	int	counter_no;
// 	int	counter_so;
// 	int	counter_we;
// 	int	counter_ea;

// 	counter_no = 0;
// 	counter_so = 0;
// 	counter_we = 0;
// 	counter_ea = 0;
// 	if (ft_strncmp(map->map[i], "NO ", 3) == 0)
// 			counter_no++;
// 		else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
// 			counter_so++;
// 		else if (ft_strncmp(map->map[i], "WE ", 3) == 0)
// 			counter_we++;
// 		else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
// 			counter_ea++;
// }

// if (ft_strncmp(map->map[i], "F ", 2) == 0)
// 			map->counter_f++;
// 		if (ft_strncmp(map->map[i], "C ", 2) == 0)
// 			map->counter_c++;
