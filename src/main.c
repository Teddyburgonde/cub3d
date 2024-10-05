/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/05 18:28:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				game->player->player_pos_x = j;
				game->player->player_pos_y = i;
				get_initial_orientation_player (game, game->data->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	// test modif for check branch
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
