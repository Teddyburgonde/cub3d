/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:21 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/05 19:41:12 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <time.h>

void	raycast(void *param)
{
	t_ray_result	ray_result;
	t_game			*game;
	float			angle_step;
	float			ray_angle;
	int				rays;
	int				i;
	clock_t			time;

	time = clock();
	game = (t_game*)param;
	rays = WINDOWS_WIDTH - 1 ; // definie le nombre de rayon a tirer
	angle_step = game->player->fov / rays; // calcul de l'angle entre les rayons qui permettra de creer une image fluide 
	i = 0;
	
	while (i < rays) // Elle parcours tous les rayons
	{
		ray_angle = game->player->angle - (game->player->fov / 2.0f) + i * angle_step; // calcul de l'angle du rayon actuel
		ray_result = ray_hit_detection(ray_angle, game); // on regarde si le rayon a toucher un mur
		draw_elements(game->texture->image, i, ray_result.wall_height, game);
		i++;
	}
	display_minimap(game);
	
	time = clock() - time;
	long fps;
	if (time != 0)
		fps = CLOCKS_PER_SEC / time;
	else
		fps = 99999999999;
	printf("fps : %li\n", fps);
	

}
