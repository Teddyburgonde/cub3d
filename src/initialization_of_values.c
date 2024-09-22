/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_of_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:34 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 12:28:01 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_of_values(t_game *game)
{
	game->player->angle = 0.0;
	game->player->pitch = 0.0;
	game->player->player_pos_x = 6;
	game->player->player_pos_y = 4;
	game->player->dir_x = -1.0;
	game->player->dir_y = 0.0;
	game->player->fov = 1.221;
	game->data->height = 300;
}
