/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:30:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/14 19:42:18 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_textures(t_game *game)
{

//	game->texture->player_position = mlx_load_png("textures/player_position.png"); //ajouté
	game->texture->player_image_N = mlx_load_png("textures/player_orientation_N.png"); //ajouté
	game->texture->player_image_E = mlx_load_png("textures/player_orientation_E.png"); //ajouté
	game->texture->player_image_S = mlx_load_png("textures/player_orientation_S.png"); //ajouté
	game->texture->player_image_W = mlx_load_png("textures/player_orientation_W.png"); //ajouté
	if(!game->texture->player_image_N || !game->texture->player_image_E
		|| !game->texture->player_image_S ||!game->texture->player_image_W)
	{
		ft_putstr_fd("Error loading texture.\n", 2);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}
