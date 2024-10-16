/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:39 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/16 14:05:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(mlx_image_t *image, int x, int up_wall, int color)
{
	int	y;

	y = 0;
	while (y < up_wall && y < WINDOWS_HEIGHT)
	{
		mlx_put_pixel(image, x, y, color);
		y++;
	}
}

static void	draw_floor(mlx_image_t *image, int x, int down_wall, int color)
{
	int	y;

	if (down_wall < 0)
		down_wall = 0;
	if (down_wall >= (int)image->height)
		return ;
	y = down_wall;
	while (y < (int)image->height && y < WINDOWS_HEIGHT)
	{
		mlx_put_pixel(image, x, y, color);
		y++;
	}
}

void	draw_elements(mlx_image_t *image,
	int x, t_game *game, float wall_height)
{
	game->ray_result.draw_start = ((int)image->height / 2.0) - \
		wall_height / 2.0;
	game->ray_result.draw_end = ((int)image->height / 2.0) + \
		wall_height / 2.0;
	draw_ceiling(image, x, game->ray_result.draw_start, \
		game->data->ceiling_color[3]);
	draw_wall_texture(game, x);
	draw_floor(image, x, game->ray_result.draw_end, game->data->floor_color[3]);
}
