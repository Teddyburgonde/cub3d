/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:21:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 22:26:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	memory_allocation_for_structs(t_game **game, char **file_content)
{
	*game = ft_calloc(1, sizeof(t_game));
	if (!(*game))
	{
		if (file_content)
			free_array(file_content);
		display_allocation_failed_and_exit(0);
	}
	(*game)->data = ft_calloc(1, sizeof(t_map_data));
	if (!(*game)->data)
	{
		if (file_content)
			free_array(file_content);
		free_structs(*game);
		display_allocation_failed_and_exit(0);
	}
	(*game)->player = ft_calloc(1, sizeof(t_player));
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	if (!(*game)->player || !(*game)->texture)
	{
		if (file_content)
			free_array(file_content);
		free_structs(*game);
		display_allocation_failed_and_exit(0);
	}
}
