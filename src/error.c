/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 01:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/19 15:05:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_allocation_failed_and_exit(int fd)
{
	ft_putstr_fd("Error: A memory allocation failed\n", 2);
	if (fd > 2)
		close(fd);
	exit(EXIT_FAILURE);
}

void	exit_when_file_is_empty(int fd)
{
	ft_putstr_fd("Error: File is empty\n", 2);
	if (fd > 2)
		close(fd);
	exit(EXIT_FAILURE);
}

void	exit_when_incorrect_color_value(char **arr, t_game *game)
{
	ft_putstr_fd("Error: Incorrect color value\n", 2);
	free_array(arr);
	free_structs(game);
	exit(EXIT_FAILURE);
}

void	exit_when_space_reachable_by_player(char **map, t_game *game)
{
	ft_putstr_fd("Error: Invalid map (space/empty space reachable \
by player)\n", 2);
	free_array(map);
	free_structs(game);
	exit(EXIT_FAILURE);
}

void	exit_when_0_non_closed_by_1(char **filled_map, t_game *game)
{
	ft_putstr_fd("Error: Invalid map (a floor not closed by wall)\n", 2);
	free_array(filled_map);
	free_structs(game);
	exit(EXIT_FAILURE);
}
