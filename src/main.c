/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 16:07:50 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_ray_result cast_ray(float rayAngle, t_game *game)
{
	t_ray_result	ray_result;

	ray_result.map_pos_x = game->player->player_pos_x; 
	ray_result.map_pos_y = game->player->player_pos_y;

	
	ray_result.ray_dist_x = cos(rayAngle); // On definie la direction horizontal du rayon où il sera envoyé plus tard
	ray_result.ray_dist_y = sin(rayAngle); // On definie la direction vertical du rayon où il sera envoyé plus tard
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
	ray_result.hit = 0;
	// Cette boucle DDA fais avancé le rayon jusqu'a qu'il touche un mur 
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
	}                                                         
	//cette ligne permet de calculer la hauteur du mur		    permet d'enleve le fisheye(distorsion visuel, les objets proches paraissent déformé)
	ray_result.wall_height = (int)((float)game->data->height / (floor(ray_result.ray_dist_perpendicular_to_wall * cos(clamp(game->player->angle - rayAngle, 0, 2 * M_PI)) * 1000) / 1000)); 
	return (ray_result);
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
		draw_elements(game->texture->image, i, ray_result.wall_height, game);
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
