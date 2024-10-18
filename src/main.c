/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/18 19:39:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		**file_content;
	t_game		*game;

	fd = 0;
	file_content = NULL;
	game = NULL;
	parsing_arguments(argc, argv);
	check_and_open_file(&fd, argv);
	file_content = get_file_content(fd);
	memory_allocation_for_structs(&game, file_content);
	initialization_of_values(game, file_content);
	parsing_file_textures(game);
	parsing_file_path_textures(game);
	parsing_file_colors(game);
	game->data->map = &game->data->file_content[game->data->begin_map_index];
	parsing_map(game);
	render_graphics(game);
	free_structs(game);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}
