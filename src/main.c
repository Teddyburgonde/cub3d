/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/18 11:37:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "math.h"

//   screen(screenWidth,screenHeight, 0, "Raycaster");

//   //load some textures
//   unsigned long tw, th, error = 0;
//   error |= loadImage(texture[0], tw, th, "pics/eagle.png");
//   error |= loadImage(texture[1], tw, th, "pics/redbrick.png");
//   error |= loadImage(texture[2], tw, th, "pics/purplestone.png");
//   error |= loadImage(texture[3], tw, th, "pics/greystone.png");
//   error |= loadImage(texture[4], tw, th, "pics/bluestone.png");
//   error |= loadImage(texture[5], tw, th, "pics/mossy.png");
//   error |= loadImage(texture[6], tw, th, "pics/wood.png");
//   error |= loadImage(texture[7], tw, th, "pics/colorstone.png");

// }

	// float	dir_x;
	// float	dir_y;

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
	game->player->player_pos_x = 6;
	game->player->player_pos_y = 5;
	game->player->dir_x = -1.0;
	game->player->dir_y = 0.0;
	game->camera->plane_x = 0.0;
	game->camera->plane_y = 0.66;
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
	
}






















// int	main(int argc, char **argv)
// {
// 	t_game *game;

// 	game = NULL;
// 	if (parsing_arguments(argc, argv) == 1)
// 		return (EXIT_FAILURE);
// 	game = ft_calloc(1, sizeof(t_game));
// 	game->data = ft_calloc(1, sizeof(t_map_data));
// 	game->texture = ft_calloc(1, sizeof(t_texture));
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
// 	game->data->map = get_map(game->data->fd);
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
// 	//game->texture->image = mlx_texture_to_image(game->mlx, game->texture->north_texture); // transformer un texture en image
// 	game->texture->image = mlx_new_image(game->mlx, 1040, 720);
// 	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
// 		return (EXIT_FAILURE);
// 	mlx_loop(game->mlx); // mlx_loop permet d'afficher la fenêtre.
// 	mlx_close_window(game->mlx); // mlx_close_window permet de fermer la fenêtre.
// 	mlx_terminate(game->mlx); // mlx_terminate permet de fermer proprement la fenêtre
// 	//ft_free(game->data->map);
// 	ft_delete_texture(game->texture);
// 	free(game->data);
// 	free(game->data->map);
// 	free(game->texture);
// 	free(game->player);
// 	free(game);
// 	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
// 	return (EXIT_SUCCESS);
// }












	
