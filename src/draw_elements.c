/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:39 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 17:48:34 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_ceiling(mlx_image_t *image, int x, int up_wall)
{
	int	y;

	y = 0;
	while (y < up_wall)
	{
		mlx_put_pixel(image, x, y, 0x00007FFF);
		y++;
	}
}

static void	draw_wall_section(mlx_image_t *image, int x,
		int up_wall, int down_wall, int color)
{
	int	y;

	y = up_wall;
	while (y < down_wall)
	{
		mlx_put_pixel(image, x, y, color); // couleur du mur
		y++;
	}
}

static void	draw_floor(mlx_image_t *image, int x, int down_wall)
{
	int	y;

	y = down_wall;
	while (y < (int)image->height)
	{
		mlx_put_pixel(image, x, y, 0xAFAFAFFF); // couleur du sol
		y++;
	}
}

void	draw_elements(mlx_image_t *image,
	int x, float wall_height, t_game *game)
{
	int		color;
	int		up_wall;
	int		down_wall;

	up_wall = ((int)image->height / 2.0) - wall_height / 2
		+ (float)(image->height / 2.0) * game->player->pitch;
	down_wall = ((int)image->height / 2.0) + wall_height / 2
		+ (float)(image->height / 2.0) * game->player->pitch;
	if (up_wall < 0)
		up_wall = 0;
	if (down_wall >= (int)image->height)
		down_wall = image->height - 1;
	color = 0xFFB400B4;
	draw_ceiling(image, x, up_wall);
	draw_wall_section(image, x, up_wall, down_wall, color);
	draw_floor(image, x, down_wall);
}
