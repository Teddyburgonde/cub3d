/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:19:55 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/09 10:50:56 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_graphics(t_game *game)
{
	game->mlx = mlx_init(WINDOWS_WIDTH, WINDOWS_HEIGHT, "cub3d", false);
	if (!game->mlx)
		exit(1); //gerer les free
	game->texture->image = mlx_new_image(game->mlx, \
	WINDOWS_WIDTH, WINDOWS_HEIGHT);
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image
		exit(1);
	load_image(game);
	mlx_key_hook(game->mlx, ft_key_mouv, (void *)game);
	mlx_loop_hook(game->mlx, raycast, (void *)game);
	mlx_loop(game->mlx);
}
