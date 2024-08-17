/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_open_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:49:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/17 16:18:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_and_open_file(t_map_data *map_data, char **argv)
{
	map_data->fd = open(argv[1], O_DIRECTORY);
	if (map_data->fd > 0)
		return (message_error_for_parsing_args("Is a directory.\n", 1));
	close(map_data->fd);
	map_data->fd = open(argv[1], O_RDONLY);
	if (map_data->fd < 0 || map_data->fd > 1023)
		return (message_error_for_parsing_args(
				"The file does not exist.\n", 1));
	return (0);
}
