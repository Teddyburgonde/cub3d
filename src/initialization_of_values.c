/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_of_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:34 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 18:13:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_of_values(t_game *game, char **map)
{
	game->player->player_pos_x = 1;
	game->player->player_pos_y = 1;
	game->player->fov = 1.221;
	game->player->angle = 0.0;
	//game->player->pitch = 0.0;

	game->data->save = 0;
//	game->data->fd = fd;
	game->data->complete_map = map;
	game->data->map = &game->data->complete_map[6];
	game->data->weight = 0;
	game->data->height = 300;//pourquoi 300 ?
	game->data->nb_lines = 0;
	game->data->nb_columns = 0;
	game->data->direction = 0;

	game->texture->image = NULL;
	game->texture->player_position_image = NULL; //pour minimap

	game->texture->minimap = NULL; //pour minimap

	game->texture->walls_image = NULL;
	game->texture->floor_image = NULL;
	game->texture->player_image = NULL; //pour minimap

	game->texture->north_texture = NULL;
	game->texture->east_texture = NULL;
	game->texture->south_texture = NULL;
	game->texture->west_texture = NULL;
	game->texture->texture = NULL;

	game->texture->player_image_N = NULL; //pour minimap
	game->texture->player_image_E = NULL; //pour minimap
	game->texture->player_image_S = NULL; //pour minimap
	game->texture->player_image_W = NULL; //pour minimap

	// voir si d'autres valeurs à initialiser 

}
