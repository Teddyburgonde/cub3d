/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_of_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:34 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 20:09:44 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_of_values(t_game *game, char **file_content)
{
	game->player->player_pos_x = 1;
	game->player->player_pos_y = 1;
	game->player->fov = 1.221;
	game->player->angle = 0.0;
	game->data->file_content = file_content;
	game->data->map = NULL;
	game->data->weight = 0;
	game->data->height = 300;
	game->data->nb_lines = 0;
	game->data->nb_columns = 0;
	game->data->lines_lenght = NULL;
	game->data->begin_map_index = 0;
	game->texture->image = NULL;
	game->texture->walls_image = NULL;
	game->texture->floor_image = NULL;
	game->texture->north_texture = NULL;
	game->texture->east_texture = NULL;
	game->texture->south_texture = NULL;
	game->texture->west_texture = NULL;
	game->texture->texture = NULL;
}
