/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:21:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 19:31:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	memory_allocation_for_structs(t_game **game)
{
	*game = ft_calloc(1, sizeof(t_game));
	(*game)->player = ft_calloc(1, sizeof(t_player));
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	(*game)->data = ft_calloc(1, sizeof(t_map_data));
	if (!(*game) || !(*game)->player || !(*game)->texture || !(*game)->data)
	{
		free_structs(*game);
		display_allocation_failed_and_exit();
	}
}
