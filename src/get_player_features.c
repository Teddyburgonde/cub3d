/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_features.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/13 10:01:14 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_player_initial_orientation(t_game *game, char facing)
{
	if (facing == 'N')
	{
		game->player->angle = 3 * M_PI / 2;
	}
	if (facing == 'E')
	{
		game->player->angle = 0;
	}
	if (facing == 'S')
	{
		game->player->angle = M_PI / 2;
	}
	if (facing == 'W')
	{
		game->player->angle = M_PI;
	}
}

void	get_player_initial_position_and_orientation(char *line, int i, int *flag, \
t_game *game)
{
	int	j;

	j = 0;
	while(line[j])
	{
		if ((line[j] == 'E' || line[j] == 'W' || \
		line[j] == 'S' || line[j] == 'N'))
		{
			game->player->player_pos_x = j + 0.5;
			game->player->player_pos_y = i + 0.5 ;
			get_player_initial_orientation (game, game->data->map[i][j]);
			*flag++ ;
		}
		j++;
	}
}
