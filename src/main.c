/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/07 09:37:29 by ppuivif          ###   ########.fr       */
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

/*void	print_arr(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}*/

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


/*int	texture_choice(t_game *game, mlx_texture **texture)
{
	float wall_pos_hit ;
	int	texture_coordinate_x;
	
	if (game->ray_result->side == 0 && cos(game->player->angle) > 0)
	{
		*texture = game->texture->east_texture;
	}
	else if (game->ray_result->side == 0 && cos(game->player->angle) <= 0)
	{
		*texture = game->texture->west_texture;
	}
	else if (game->ray_result->side == 1 && sin(game->player->angle) > 0)
	{
		*texture = game->texture->south_texture;
	}
	else 
	{
		*texture = game->texture->north_texture;
	}
	if (game->ray_result->side == 0)
	{
		wall_pos_hit = game->player->player_pos_y + game->ray_result->ray_dist_perpendicular_to_wall * game->ray_result->ray_dist_y;
	}
	else 
	{
		wall_pos_hit = game->player->player_pos_x + game->ray_result->ray_dist_perpendicular_to_wall * game->ray_result->ray_dist_x;
	}
	wall_pos_hit -= floor(wall_pos_hit);
	texture_coordinate_x = (int)wall_pos_hit * (double)TEX_WIDTH;
	if (game->ray_result->side == 0 && game->ray_result->ray_dist_perpendicular_to_wall > 0)
		texture_coordinate_x = TEX_WIDTH - 1;
	if (game->ray_result->side == 1 && game->ray_result->ray_dist_perpendicular_to_wall < 0)
		texture_coordinate_x = TEX_WIDTH - 1;
	return (texture_coordinate_x);
}*/


// How much to increase the texture coordinate per screen pixel
//       double step = 1.0 * texHeight / lineHeight;
//       // Starting texture coordinate
//       double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
//       for(int y = drawStart; y<drawEnd; y++)
//       {
//         // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
//         int texY = (int)texPos & (texHeight - 1);
//         texPos += step;
//         Uint32 color = texture[texNum][texHeight * texY + texX];
//         //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
//         if(side == 1) color = (color >> 1) & 8355711;
//         buffer[y][x] = color;
//       }
//     }


int	main(int argc, char **argv)
{
	// test modif for check branch
	int		fd;
	char	**map;
	t_game	*game;
	Uint32	*texture[8];
	

	fd = 0;
	game = NULL;
	
	parsing_arguments(argc, argv);
	check_and_open_file(&fd, argv);
	map = get_map(fd);
	memory_allocation_for_struct(&game);
	initialization_of_values(game, fd, map);
	parsing_map_elements(game);
	if (parse_map(game->data) == 1)
		exit(EXIT_FAILURE);//free des allocations
	game->data->map = &game->data->map[6];

	get_map_size(game->data);
	get_player_position_and_orientation(game);

	allocate_textures(texture); //utile ?

	render_graphics (game);
	close_and_free(game);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
