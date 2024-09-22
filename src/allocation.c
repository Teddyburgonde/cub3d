/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:21:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 18:37:19 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	memory_allocation_for_struct(t_game **game)
{
	*game = ft_calloc(1, sizeof(t_game));
	(*game)->player = ft_calloc(1, sizeof(t_player));
	(*game)->texture = ft_calloc(1, sizeof(t_texture));
	(*game)->data = ft_calloc(1, sizeof(t_map_data));
	if (!(*game) || !(*game)->player || !(*game)->texture || !(*game)->data)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
		exit (1);
	}
}

void	allocate_textures(Uint32 *texture[8])
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		texture[i] = (Uint32 *)malloc(64 * 64 * sizeof(Uint32));
		if (texture[i] == NULL)
		{
			ft_putstr_fd("Allocation error\n", 2);
			j = 0;
			while (j < i)
			{
				free(texture[j]);
				j++;
			}
			exit(1);
		}
		i++;
	}
}
