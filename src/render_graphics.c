/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:19:55 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 15:21:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_graphics(t_game *game)
{
	game->mlx = mlx_init(1040, 720, "cub3d", false);
	if (!game->mlx)
		exit(1);
	game->texture->image = mlx_new_image(game->mlx, 1040, 720);
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
		exit(1);
	load_image(game);
	mlx_key_hook(game->mlx, ft_key_mouv, (void*)game);
	mlx_loop_hook(game->mlx, raycast, (void*)game);
	mlx_loop(game->mlx);
}
