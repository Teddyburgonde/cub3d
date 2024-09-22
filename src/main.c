/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 15:27:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// #include "../MLX42/include/MLX42/MLX42.h" 

t_ray_result cast_ray(float rayAngle, t_game *game)
{
	t_ray_result	ray_result;
	
	// map_pos_x et map_pos_y sont les coordonnées de la carte où le rayon a touché un mur
	// map_pos c'est la position dans le tableau 
	ray_result.map_pos_x = game->player->player_pos_x; 
	ray_result.map_pos_y = game->player->player_pos_y;
	ray_result.ray_dist_x = cos(rayAngle);
	ray_result.ray_dist_y = sin(rayAngle);
	if (ray_result.ray_dist_x == 0)
		ray_result.delta_dist_x = 1e30;
	else
		ray_result.delta_dist_x = fabs(1 / ray_result.ray_dist_x);
	if (ray_result.ray_dist_y == 0)
		ray_result.delta_dist_y = 1e30;
	else
		ray_result.delta_dist_y = fabs(1 / ray_result.ray_dist_y);
	if (ray_result.ray_dist_x < 0)
	{
		ray_result.step_x = -1;
		ray_result.ray_dist_x = (game->player->player_pos_x - ray_result.map_pos_x) * ray_result.delta_dist_x;
	}
	else
	{
		ray_result.step_x = 1;
		ray_result.ray_dist_x = (ray_result.map_pos_x + 1.0 - game->player->player_pos_x) * ray_result.delta_dist_x;
	}
	if (ray_result.ray_dist_y < 0)
	{
		ray_result.step_y = -1;
		ray_result.ray_dist_y = (game->player->player_pos_y - ray_result.map_pos_y) * ray_result.delta_dist_y;
	}
	else
	{
		ray_result.step_y = 1;
		ray_result.ray_dist_y = (ray_result.map_pos_y + 1.0 - game->player->player_pos_y) * ray_result.delta_dist_y;
	}
	// perform DDA
	ray_result.hit = 0;
	while (ray_result.hit == 0)
	{
		if (ray_result.ray_dist_x < ray_result.ray_dist_y)
		{
			ray_result.ray_dist_x += ray_result.delta_dist_x;
			ray_result.map_pos_x += ray_result.step_x;
			ray_result.side = 0;
		}
		else
		{
			ray_result.ray_dist_y += ray_result.delta_dist_y;
			ray_result.map_pos_y += ray_result.step_y;
			ray_result.side = 1;
		}
		if (game->data->map[ray_result.map_pos_y][ray_result.map_pos_x] == '1') // verifie si le rayon a touché un mur
			ray_result.hit = 1;
		if (ray_result.side == 0)
			ray_result.ray_dist_perpendicular_to_wall = (ray_result.ray_dist_x - ray_result.delta_dist_x);
		else
			ray_result.ray_dist_perpendicular_to_wall = (ray_result.ray_dist_y - ray_result.delta_dist_y);
	}                                                           // permet d'enleve le fisheye   
	ray_result.wall_height = (int)((float)game->data->height / (floor(ray_result.ray_dist_perpendicular_to_wall * cos(clamp(game->player->angle - rayAngle, 0, 2 * M_PI)) * 1000) / 1000)); 
	return (ray_result);
}

void	 draw_wall(mlx_image_t* image, int x, float wall_height, t_game *game)
{
	int		color;
	int		up_wall;
	int		down_wall;
	int	y;

	y = 0;
	up_wall = ((int)image->height / 2.0) - wall_height / 2 + (float)(image->height / 2.0) * game->player->pitch;
	down_wall = ((int)image->height / 2.0) + wall_height / 2 + (float)(image->height / 2.0) * game->player->pitch;
	if (up_wall < 0)
		up_wall = 0;
	if (down_wall >= (int)image->height)
		down_wall = image->height - 1;   
	color = 0xFFB400B4;
	while (y < up_wall)
	{
		mlx_put_pixel(image, x, y, 0x00007FFF);
		y++;
	}
	while (y < down_wall)
	{
		mlx_put_pixel(image, x, y, color);
		y++;
	}
	while (y < (int)image->height)
	{
		mlx_put_pixel(image, x, y, 0xAFAFAFFF);
		y++;
	}
}
void	raycast(void *param)
{
	t_ray_result	ray_result;
	t_game			*game;
	float			angle_step;
	float			ray_angle;
	int				rays;
	int				i;

	game = (t_game*)param;
	rays = 1039;
	angle_step = game->player->fov / rays;
	i = 0;
	// murs 
	while (i < rays)
	{
		ray_angle = game->player->angle - (game->player->fov / 2.0f) + i * angle_step;
		ray_result = cast_ray(ray_angle, game);
		draw_wall(game->texture->image, i, ray_result.wall_height, game);
		i++;
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
		return (EXIT_FAILURE);
	parsing_map_elements(game);
	if (parse_map(game->data) == 1)
		exit(1);
	game->data->map = &game->data->map[6];
	allocate_textures(texture, 8);
	render_graphics (game);
	close_and_free(game);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
