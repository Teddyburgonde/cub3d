/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_displaying.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:01:43 by ppuivif           #+#    #+#             */
/*   Updated: 2024/10/10 18:30:36 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pos_texture(t_game *game)
{
	int	texture_coordinate_x;
	
	if (game->ray_result.side == 0)
	{
		game->ray_result.wall_pos_hit = game->player->player_pos_y + game->ray_result.ray_dist_perpendicular_to_wall * game->ray_result.ray_dist_y;
	}
	else 
	{
		game->ray_result.wall_pos_hit = game->player->player_pos_x + game->ray_result.ray_dist_perpendicular_to_wall * game->ray_result.ray_dist_x;
	}
	game->ray_result.wall_pos_hit -= floor(game->ray_result.wall_pos_hit);
	texture_coordinate_x = (int)game->ray_result.wall_pos_hit * (double)TEX_WIDTH;
	if (game->ray_result.side == 0 && game->ray_result.ray_dist_perpendicular_to_wall > 0)
		texture_coordinate_x = TEX_WIDTH - 1;
	if (game->ray_result.side == 1 && game->ray_result.ray_dist_perpendicular_to_wall < 0)
		texture_coordinate_x = TEX_WIDTH - 1;	
}

void	texture_choice(t_game *game)
{
    if (game->ray_result.side == 0 && cos(game->ray_result.ray_angle) > 0)
	{
		game->texture->texture = game->texture->west_texture;
	}
	else if (game->ray_result.side == 0 && cos(game->ray_result.ray_angle) <= 0)
	{
		game->texture->texture = game->texture->east_texture;
	}
	else if (game->ray_result.side == 1 && sin(game->ray_result.ray_angle) > 0)
	{
		game->texture->texture = game->texture->north_texture;
	}
	else 
	{
		game->texture->texture = game->texture->south_texture;
	}
}

void	draw_wall_texture(t_game *game, int x)
{
	
	int	y;
	int text_y;
	int	pixel;
	float text_x;
	y = game->ray_result.draw_start;
	if (y < 0)
		y = 0;
	if (game->ray_result.side == 0)
	{
		text_x = game->player->player_pos_y + game->ray_result.ray_dist_perpendicular_to_wall * sin(game->ray_result.ray_angle);
	}
	else 
	{
		text_x = game->player->player_pos_x + game->ray_result.ray_dist_perpendicular_to_wall * cos(game->ray_result.ray_angle);
	}
	text_x -= floor(text_x);
	text_x = (int)(text_x * (double)game->texture->texture->width);
	if ((game->ray_result.side == 0 && cos(game->ray_result.ray_angle) > 0 ) || ((game->ray_result.side == 1) && sin(game->ray_result.ray_angle) < 0))
	{
		text_x = game->texture->texture->width - text_x - 1;
	}
	while (y < game->ray_result.draw_end && y < WINDOWS_HEIGHT)
	{
		text_y = (int)((y - game->ray_result.draw_start) * ((float)game->texture->texture->height / (game->ray_result.draw_end - game->ray_result.draw_start))); 
		pixel = (game->texture->texture->width * text_y + text_x) * 4; // remove * 4 RGBA	
		mlx_put_pixel(game->texture->image, x, y, ft_pixel(game->texture->texture->pixels[pixel], game->texture->texture->pixels[pixel + 1], game->texture->texture->pixels[pixel + 2]));
		y++;
	}
}