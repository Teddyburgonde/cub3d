/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 20:50:24 by ppuivif          ###   ########.fr       */
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
		ft_putstr_fd("Error: One or more way to texture/color is missing \
or redundant\n", 2);
		free_structs(game);
		exit (EXIT_FAILURE);
	}
}

void	parsing_file_textures(t_game *game)
{
	int					i;
	char				*tmp;
	t_counter_parameter	counter_parameter;

	i = 0;
	ft_memset(&counter_parameter, 0, sizeof(t_counter_parameter));
	while (game->data->file_content[i])
	{
		tmp = skip_first_spaces(game->data->file_content[i]);
		if (ft_strncmp(tmp, "NO ", 3) == 0)
			counter_parameter.counter_no++;
		if (ft_strncmp(tmp, "SO ", 3) == 0)
			counter_parameter.counter_so++;
		if (ft_strncmp(tmp, "WE ", 3) == 0)
			counter_parameter.counter_we++;
		if (ft_strncmp(tmp, "EA ", 3) == 0)
			counter_parameter.counter_ea++;
		if (ft_strncmp(tmp, "F ", 2) == 0)
			counter_parameter.counter_f++;
		if (ft_strncmp(tmp, "C ", 2) == 0)
			counter_parameter.counter_c++;
		i++;
	}
	check_if_missing_element(counter_parameter, game);
}
