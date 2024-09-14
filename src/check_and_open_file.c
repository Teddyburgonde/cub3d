/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_open_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:49:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/14 11:50:38 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_and_open_file(t_game *game, char **argv)
{
	game->data->fd = open(argv[1], O_DIRECTORY);
	if (game->data->fd > 0)
	{
		close(game->data->fd);
		return (message_error_for_parsing_args("Is a directory.\n", 1));
	}
	game->data->fd = open(argv[1], O_RDONLY);
	if (game->data->fd < 0 || game->data->fd > 1023)
		return (message_error_for_parsing_args(
				"The file does not exist.\n", 1));
	return (0);
}
