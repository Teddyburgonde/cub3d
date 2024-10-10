/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 18:06:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_if_missing_element(t_counter_parameter counter_parameter, \
t_game *game)
{
	if (counter_parameter.counter_no != 1 || counter_parameter.counter_so != 1
		|| counter_parameter.counter_we != 1
		|| counter_parameter.counter_ea != 1
		|| counter_parameter.counter_f != 1 || counter_parameter.counter_c != 1)
	{
		ft_putstr_fd("Error: One or more way to texture/color is missing.\n", 2);
		free_structs(game);
		exit (EXIT_FAILURE);
	}
}

void	parse_map_textures(t_game *game)
{
	int					i;
	char 				**map;
	t_counter_parameter	counter_parameter;

	i = 0;
	map = game->data->complete_map;
	ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));//valider la fonction memset
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			counter_parameter.counter_no++;
		if (ft_strncmp(map[i], "SO ", 3) == 0)
			counter_parameter.counter_so++;
		if (ft_strncmp(map[i], "WE ", 3) == 0)
			counter_parameter.counter_we++;
		if (ft_strncmp(map[i], "EA ", 3) == 0)
			counter_parameter.counter_ea++;
		if (ft_strncmp(map[i], "F ", 2) == 0)
			counter_parameter.counter_f++;
		if (ft_strncmp(map[i], "C ", 2) == 0)
			counter_parameter.counter_c++;
		i++;
	}
	check_if_missing_element(counter_parameter, game);
}
