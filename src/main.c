/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/14 15:44:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	game->data = ft_calloc(1, sizeof(t_map_data));
	game->texture = ft_calloc(1, sizeof(t_texture));
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
	close(game->data->fd);

	game->mlx = mlx_init(1040, 720, "cub3d", false); // mlx_init permet de cree la fenêtre.
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->texture->image = mlx_texture_to_image(game->mlx, game->texture->north_texture); // transformer un texture en image
	if (mlx_image_to_window(game->mlx, game->texture->image, 0, 0) < 0) // affiche l'image 
		return (EXIT_FAILURE);

	//! JE SUIS ICI 
	mlx_loop_hook(game->mlx, /*function*/, game->mlx);

	
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












	
