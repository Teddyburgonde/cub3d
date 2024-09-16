/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/16 17:45:54 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "math.h"

// function castRay 
// elle doit retourner distance et wallHeight

typedef struct {
    float distance;
    float wall_height;
} t_ray_result;

// elle return un t_rayResult qui contient la distance ou il y a le mur
// et la hauteur du mur )
// et elle prends en entree l'angle en fonction duquel tu lances le rayon. 

t_ray_result cast_ray(float rayAngle, t_game *game)
{
	t_ray_result	ray_result;

	// initialisation des variables
	float x;
	float y;
	float dx;
	float dy;
	int	i;
	int map_x;
	int	map_y;
	
	x = game->player->player_pos_x;
	y = game->player->player_pos_y;
	dx = cos(rayAngle);
    dy = sin(rayAngle);
	i = 0;
	while (i < 400) // la boucle continue tant qu'il ne trouve pas de mur
	{
		map_x = (int)floor(x);
		map_y = (int)floor(y);
		if (game->data->map[map_y][map_x] == '1')
			break; // Il a trouver un mur
		x += dx * 0.1f;
        y += dy * 0.1f;
		i++;
	}
	
	// Calcul de la distance et de la hauteur du mur
	ray_result.distance = sqrtf((x - game->player->player_pos_x) * (x - game->player->player_pos_x) + 
		(y - game->player->player_pos_y) * (y - game->player->player_pos_y));
	ray_result.wall_height = 300.0f / ray_result.distance;

	return (ray_result);
}

// Function pour dessiner les murs en fonction de la distance parcourue par les rayons
void	draw_wall(mlx_image_t* image, int j, float wall_height, float slice_width)
{
	int	y_position;
	int		color;
	
	color = 0xFFB400B4;

	y_position = 0;
	for (int i = 0; i < (int)wall_height; i++)
	{
		// Calcul de la position en Y
		y_position = (int)floor(300 - wall_height / 2 + i);
		if (y_position >= 0 && y_position < (int)image->height) // Vérification que y_position est dans les limites de l'écran
        {
			// Dessine le slice verticale(petite bande) avec la larguer donnée
			for(int k = 0; k < (int)slice_width; k++)
			{
				if (j * slice_width + k < image->width)  // Vérification des limites X
                {
					mlx_put_pixel(image, j * slice_width + k, y_position, color);
				}
			}
		}	
	}
}
// Tous nos rayons et murs proviennent de cette fonction :
void	raycast(void *param)
{
	int	rays;
	int	screen_width;
	int	slice_width;
	int	angle_step;
	int ray_angle;
	t_ray_result	ray_result;
	t_game *game;


	game = (t_game*)param;
	rays = 200;
	screen_width = 800;
	slice_width = screen_width / rays;
	angle_step = game->player->fov / rays;

	// murs 
	for (int i = 0; i < rays; i++)
	{
		ray_angle = game->player->angle - (game->player->fov / 2) + i * angle_step;
		ray_result = cast_ray(ray_angle, game);
		draw_wall(game->texture->image, i, ray_result.wall_height, slice_width);
	}
	// mlx_image_to_window(game->mlx, game->texture->image, 0, 0);
}

int	main(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	game->data = ft_calloc(1, sizeof(t_map_data));
	game->texture = ft_calloc(1, sizeof(t_texture));
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->fov = 1.5 * M_PI;
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
	ft_print_value_map(game->data);

	close(game->data->fd);
	game->player->player_pos_x = 6;
	game->player->player_pos_y = 5;

	game->mlx = mlx_init(1040, 720, "cub3d", false); // mlx_init permet de cree la fenêtre.
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->texture->image = mlx_texture_to_image(game->mlx, game->texture->north_texture); // transformer un texture en image
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
		return (EXIT_FAILURE);

	//! JE SUIS ICI
	mlx_loop_hook(game->mlx, raycast, (void*)game);

	mlx_loop(game->mlx); // mlx_loop permet d'afficher la fenêtre.
	mlx_close_window(game->mlx); // mlx_close_window permet de fermer la fenêtre.
	mlx_terminate(game->mlx); // mlx_terminate permet de fermer proprement la fenêtre
	ft_free(game->data->map);
	free(game->data);
	free(game->texture);
	free(game);
	ft_delete_texture(game->texture);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}












	
