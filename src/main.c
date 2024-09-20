/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/20 16:53:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "math.h"

// https://lodev.org/cgtutor/raycasting2.html

float	clamp(float num, float min, float max)
{
	if (num < min)
		return (max + num);
	if (num > max)
		return (num - max);
	return (num);
}

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

void	 draw_wall(mlx_image_t* image, int x, float wall_height)
{
	int		color;
	int		up_wall;
	int		down_wall;
	int	y;

	y = 0;
	up_wall = ((int)image->height / 2) - wall_height / 2;
	down_wall = ((int)image->height / 2) + wall_height / 2;
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
	int	rays;
	float	angle_step;
	float ray_angle;
	t_ray_result	ray_result;
	t_game *game;


	game = (t_game*)param;
	rays = 1039;
	angle_step = game->player->fov / rays;

	// murs 
	for (int i = 0; i < rays; i++)
	{
		ray_angle = game->player->angle - (game->player->fov / 2.0f) + i * angle_step;
		ray_result = cast_ray(ray_angle, game);
		draw_wall(game->texture->image, i, ray_result.wall_height);
	}
}

// 1ere etape : mouvement

// mlx_key_handle(mlx_keydata_t keydata, void*param)
// <- tourne la tete a gauche 
// -> tourne la tete a droite
// ^ personnage avance
// \/ personnage recule

// 2eme etape : colision

// 3eme etape : Nettoyage  


typedef unsigned int Uint32;

int	main(int argc, char **argv)
{
	t_game	*game;
	int		i;
	int		j;

	game = NULL;
	i = 0;
	j = 0;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	Uint32* texture[8];
	game = ft_calloc(1, sizeof(t_game));
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->angle = 0.0;
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->data = ft_calloc(1, sizeof(t_map_data));
	if (check_and_open_file(game, argv) == 1)
		return (EXIT_FAILURE);
	game->data->map = get_map(game->data->fd);
	if (!game->data->map)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements(game->data) == 1)
		return (EXIT_FAILURE);
	if (ft_parse_map_path_texture(game->data, game->texture) != 0)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements_colors(game->data) != 0)
		return (EXIT_FAILURE);
	parse_map(game->data);
	game->data->map = &game->data->map[6];
	game->player->player_pos_x = 6;
	game->player->player_pos_y = 5;
	game->player->dir_x = -1.0;
	game->player->dir_y = 0.0;
	game->player->fov = 1.221;
	game->data->height = 300;
	while (i < 8)
	{
		texture[i] = (Uint32*)malloc(64* 64 * sizeof(Uint32));
		if (texture[i] == NULL)
		{
			ft_putstr_fd("Allocation error\n", 2);
			while (j < i)
			{
				free(texture[j]);
				j++;
			}
			return (EXIT_FAILURE);
		}
		i++;
	}
	game->mlx = mlx_init(1040, 720, "cub3d", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->texture->image = mlx_new_image(game->mlx, 1040, 720);
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
		return (EXIT_FAILURE);
	game->texture->east_texture = mlx_load_png("textures/wall_ea.png");
	game->texture->west_texture = mlx_load_png("textures/wall_we.png");
	game->texture->south_texture = mlx_load_png("textures/wall_so.png");
	game->texture->north_texture = mlx_load_png("textures/wall_no.png");
	if (!game->texture->east_texture || !game->texture->west_texture || !game->texture->south_texture || !game->texture->north_texture)
	{
		ft_putstr_fd("Error loading texture\n", 2);
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(game->mlx, raycast, (void*)game);
	mlx_loop(game->mlx);
	
}



















// int	main(int argc, char **argv)
// {
// 	t_game *game;

// 	game = NULL;
// 	if (parsing_arguments(argc, argv) == 1)
// 		return (EXIT_FAILURE);
// 	game = ft_calloc(1, sizeof(t_game));
// 	game->player = ft_calloc(1, sizeof(t_player));
// 	if (!game->data || !game->texture || !game->player)
//     {
//         free(game);
//         return (EXIT_FAILURE);
//     }
// 	// game->player->fov = 1.5 * M_PI;
// 	game->player->fov = 1.221;
// 	if (check_and_open_file(game, argv) == 1)
// 		return (EXIT_FAILURE);
// 	if (!game->data->map)
// 		return (EXIT_FAILURE);
// 	if (ft_parse_map_elements(game->data) == 1)
// 		return (EXIT_FAILURE);
// 	if (ft_parse_map_path_texture(game->data, game->texture) != 0)
// 		return (EXIT_FAILURE);
// 	if (ft_parse_map_elements_colors(game->data) != 0)
// 		return (EXIT_FAILURE);
// 	parse_map(game->data);
// 	game->data->map = &game->data->map[6];
// 	//ft_print_value_map(game->data);
// 	close(game->data->fd);
// 	game->player->player_pos_x = 6;
// 	game->player->player_pos_y = 5;
// 	game->mlx = mlx_init(1040, 720, "cub3d", false); // mlx_init permet de cree la fenêtre.
// 	if (!game->mlx)
// 		return (EXIT_FAILURE);
// 	game->texture->image = mlx_new_image(game->mlx, 1040, 720);
// 	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
// 		return (EXIT_FAILURE);
// 	mlx_loop(game->mlx); // mlx_loop permet d'afficher la fenêtre.
// 	mlx_close_window(game->mlx); // mlx_close_window permet de fermer la fenêtre.
// 	mlx_terminate(game->mlx); // mlx_terminate permet de fermer proprement la fenêtre
// 	ft_delete_texture(game->texture);
// 	free(game->data);
// 	free(game->data->map);
// 	free(game->texture);
// 	free(game->player);
// 	free(game);
// 	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
// 	return (EXIT_SUCCESS);
// }












	
