/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:19:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/19 15:29:30 by ppuivif          ###   ########.fr       */
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

static int	count_parameters(char *tmp, t_counter_parameter	*counter_parameter)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0)
		counter_parameter->counter_no++;
	else if (ft_strncmp(tmp, "SO ", 3) == 0)
		counter_parameter->counter_so++;
	else if (ft_strncmp(tmp, "WE ", 3) == 0)
		counter_parameter->counter_we++;
	else if (ft_strncmp(tmp, "EA ", 3) == 0)
		counter_parameter->counter_ea++;
	else if (ft_strncmp(tmp, "F ", 2) == 0)
		counter_parameter->counter_f++;
	else if (ft_strncmp(tmp, "C ", 2) == 0)
		counter_parameter->counter_c++;
	else
		return (0);
	return (1);
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
		if (count_parameters(tmp, &counter_parameter) == 0)
			break ;
		i++;
	}
	game->data->begin_map_index = i;
	check_if_missing_element(counter_parameter, game);
}
