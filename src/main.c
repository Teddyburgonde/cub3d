/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/07 15:40:46 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

static void	get_map_size(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	while(map_data->map[i])
	{
		j = 0;
		while(map_data->map[i][j])
			j++;
		if(map_data->nb_columns <= j)
			map_data->nb_columns = j;
		i++;
	}
	map_data->nb_lines = i;
}

void	get_initial_orientation_player(t_game *game, char facing)
{
	if (facing == 'N')
	{
		game->player->angle = 3 * M_PI / 2;
	}
	if (facing == 'E')
	{
		game->player->angle = 0;
	}
	if (facing == 'S')
	{
		game->player->angle = M_PI / 2;
	}
	if (facing == 'W')
	{
		game->player->angle = M_PI;
	}
}

void	get_player_position_and_orientation(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(game->data->map[i])
	{
		j = 0;
		while(game->data->map[i][j])
		{
			if (game->data->map[i][j] == 'E' || \
			game->data->map[i][j] == 'W' || \
			game->data->map[i][j] == 'S' || \
			game->data->map[i][j] == 'N')
			{
				game->player->player_pos_x = j + 0.5;
				game->player->player_pos_y = i + 0.5 ;
				get_initial_orientation_player (game, game->data->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

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
	if (game->ray_result.side == 0 && cos(game->player->angle) > 0)
	{
		game->texture->texture = game->texture->east_texture;
	}
	else if (game->ray_result.side == 0 && cos(game->player->angle) <= 0)
	{
		game->texture->texture = game->texture->west_texture;
	}
	else if (game->ray_result.side == 1 && sin(game->player->angle) > 0)
	{
		game->texture->texture = game->texture->south_texture;
	}
	else 
	{
		game->texture->texture = game->texture->north_texture;
	}
}

void	draw_wall_texture(t_game *game, int x)
{
	
	int	y;
	int text_y;
	int	pixel;
	float text_x;
	y = game->ray_result.draw_start;
	if (game->ray_result.side == 0)
	{
		text_x = game->ray_result.map_pos_y + game->ray_result.ray_dist_perpendicular_to_wall * sin(game->ray_result.angle);
	}
	else 
	{
		text_x = game->ray_result.map_pos_x + game->ray_result.ray_dist_perpendicular_to_wall * cos(game->ray_result.angle);
	}
	text_x -= floor(text_x);
	text_x = (int)(text_x * (double)game->texture->texture->width);
	if ((game->ray_result.side == 0 && cos(game->ray_result.angle) > 0 ) || ((game->ray_result.side == 1) && sin(game->ray_result.angle) < 0))
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

int	main(int argc, char **argv)
{
	t_game	*game;
	Uint32	*texture[8];

	game = NULL;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	memory_allocation_for_struct(&game);
	initialization_of_values(game);
	if (check_and_open_file(game, argv) == 1)
		return (EXIT_FAILURE);
	game->data->map = get_map(game->data->fd);
	if (!game->data->map)
		return (EXIT_FAILURE);//verifier si GNL renvoie NULL en dehors d'une erreur d'allocation
	parsing_map_elements(game);
	if (parse_map(game->data) == 1)
		exit(1);//free des allocations
	game->data->map = &game->data->map[6];

	get_map_size(game->data);
	get_player_position_and_orientation(game);

	allocate_textures(texture);

	render_graphics (game);
	close_and_free(game);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
