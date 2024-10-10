/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:30:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 09:48:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_image(t_game *game)
{
/*	game->texture->east_texture = mlx_load_png("textures/wall_ea.png");
	game->texture->west_texture = mlx_load_png("textures/wall_we.png");
	game->texture->south_texture = mlx_load_png("textures/wall_so.png");
	game->texture->north_texture = mlx_load_png("textures/wall_no.png");
	if (!game->texture->east_texture || !game->texture->west_texture
		|| !game->texture->south_texture || !game->texture->north_texture)
	{
		ft_putstr_fd("Error loading texture\n", 2);//free des allocations à prévoir
		exit(1);
	}*/

//	game->texture->player_position = mlx_load_png("textures/player_position.png"); //ajouté
	game->texture->player_image_N = mlx_load_png("textures/player_orientation_N.png"); //ajouté
	game->texture->player_image_E = mlx_load_png("textures/player_orientation_E.png"); //ajouté
	game->texture->player_image_S = mlx_load_png("textures/player_orientation_S.png"); //ajouté
	game->texture->player_image_W = mlx_load_png("textures/player_orientation_W.png"); //ajouté
	if(!game->texture->player_image_N || !game->texture->player_image_E
		|| !game->texture->player_image_S ||!game->texture->player_image_W)
	{
		ft_putstr_fd("Error loading texture\n", 2);//free des allocations à prévoir
		exit(EXIT_FAILURE);
	}
}
