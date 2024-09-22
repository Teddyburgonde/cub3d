/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:21 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/22 17:07:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycast(void *param)
{
	t_ray_result	ray_result;
	t_game			*game;
	float			angle_step;
	float			ray_angle;
	int				rays;
	int				i;

	game = (t_game*)param;
	rays = 1039;
	angle_step = game->player->fov / rays;
	i = 0;
	while (i < rays)
	{
		ray_angle = game->player->angle - (game->player->fov / 2.0f) + i * angle_step;
		ray_result = ray_hit_detection(ray_angle, game);
		draw_elements(game->texture->image, i, ray_result.wall_height, game);
		i++;
	}
}
