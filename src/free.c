/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:28 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/12 15:27:17 by tebandam         ###   ########.fr       */
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

void	ft_delete_texture(t_texture texture)
{
	if (texture.north_texture)
		mlx_delete_texture(texture.north_texture);
	if (texture.south_texture)
		mlx_delete_texture(texture.south_texture);
	if (texture.east_texture)
		mlx_delete_texture(texture.east_texture);
	if (texture.west_texture)
		mlx_delete_texture(texture.west_texture);
}

