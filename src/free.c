/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:28 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 18:06:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static void	delete_texture(t_texture *texture)
{
	if (texture->north_texture)
		mlx_delete_texture(texture->north_texture);
	if (texture->south_texture)
		mlx_delete_texture(texture->south_texture);
	if (texture->east_texture)
		mlx_delete_texture(texture->east_texture);
	if (texture->west_texture)
		mlx_delete_texture(texture->west_texture);
}

void	free_structs(t_game *game)
{
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	if (game->player)
		free(game->player);
	if (game->texture)
		delete_texture(game->texture);
	if (game->texture)
		free(game->texture);
	if (game->data->complete_map)
		free_array(game->data->complete_map);
	if (game->data)
		free(game->data);
	if (game)
		free(game);
}
