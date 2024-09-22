/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:28 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 12:49:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_delete_texture(t_texture *texture)
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

void	close_and_free(t_game *game)
{
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	if (game->texture)
		ft_delete_texture(game->texture);
	if (game->data)
		free(game->data);
	if (game->texture)
		free(game->texture);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
}
