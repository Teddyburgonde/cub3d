/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_detection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:04:10 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/09 19:18:30 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Cette boucle DDA fais avancé le rayon jusqu'a qu'il touche un mur
static t_ray_result	perform_dda(t_ray_result ray_result, char **map)
{
	ray_result.hit = 0;
	while (ray_result.hit == 0)
	{
		if (ray_result.ray_dist_x < ray_result.ray_dist_y) // Compare les distances pour déterminer quel axe avancer en premier
		{
			ray_result.ray_dist_x += ray_result.delta_dist_x; // Avance sur l'axe X
			ray_result.map_pos_x += ray_result.step_x; // Met à jour la position dans la carte
			ray_result.side = 0; // Indique que l'on regarde un cote de la case, parallele à l'axe des y (une ligne verticale)
		}
		else
		{
			ray_result.ray_dist_y += ray_result.delta_dist_y; // Avance sur l'axe y
			ray_result.map_pos_y += ray_result.step_y; // Met à jour la position dans la carte
			ray_result.side = 1; // Indique que l'on a touché un mur sur l'axe y
		}
		if (map[ray_result.map_pos_y][ray_result.map_pos_x] == '1') // Vérifie si le rayon a touché un mur
			ray_result.hit = 1; // Met à jour hit à 1 pour indiquer qu'on a touché un mur
		if (ray_result.side == 0)
			ray_result.ray_dist_perpendicular_to_wall = (ray_result.ray_dist_x - ray_result.delta_dist_x); // Calcule la distance perpendiculaire au mur en fonction de l'axe touché
		else
			ray_result.ray_dist_perpendicular_to_wall = (ray_result.ray_dist_y - ray_result.delta_dist_y); // Calcule la distance perpendiculaire au mur en fonction de l'axe touché
	}
	return (ray_result);
}

static void	initialize_ray(t_ray_result *ray_result, t_game *game, float ray_angle)
{
	ray_result->map_pos_x = game->player->player_pos_x; // Définit le point de départ du rayon horizontal
	ray_result->map_pos_y = game->player->player_pos_y; // Définit le point de départ du rayon vertical
	ray_result->ray_dist_x = cos(ray_angle); // On definie la direction horizontal du rayon où il sera envoyé plus tard
	ray_result->ray_dist_y = sin(ray_angle); // On definie la direction vertical du rayon où il sera envoyé plus tard

}

static void	calcul_delta(t_ray_result *ray_result)
{
	// Calcul du delta_dist_x
	if (ray_result->ray_dist_x == 0)
		ray_result->delta_dist_x = 1e30; // Si le rayon est parfaitement vertical, on met une grande valeur
	else
		ray_result->delta_dist_x = fabs(1 / ray_result->ray_dist_x);// Sinon on calcule le delta pour l'axe X
	// Calcul du delta_dist_y
	if (ray_result->ray_dist_y == 0)
		ray_result->delta_dist_y = 1e30; // Si le rayon est parfaitement horizontal, on met une grande valeur
	else
		ray_result->delta_dist_y = fabs(1 / ray_result->ray_dist_y); // Sinon on calcule le delta pour l'axe Y
}

static void	initialize_ray_step_and_distance(t_ray_result *ray_result,
	t_game *game)
{
	// Vérifie la direction du rayon sur l'axe X
//	printf("player_pos_x : %f\n", game->player->player_pos_x);
//	printf("ray_result->map_pos_x : %d\n", ray_result->map_pos_x);

	if (ray_result->ray_dist_x < 0)
	{
		ray_result->step_x = -1; // Si la direction est négative, on va verifier la case vers la gauche dans la carte
		ray_result->ray_dist_x = (game->player->player_pos_x - ray_result->map_pos_x) * ray_result->delta_dist_x; // Calcule la distance à la prochaine ligne de la carte sur l'axe X
	}
	else
	{
		ray_result->step_x = 1; // Si la direction est positive, on va verifier la case vers la droite dans la carte
		ray_result->ray_dist_x = (ray_result->map_pos_x + 1.0 - game->player->player_pos_x) * ray_result->delta_dist_x; // Calcule la distance à la prochaine ligne de la carte sur l'axe X
	}
	// Vérifie la direction du rayon sur l'axe X
	if (ray_result->ray_dist_y < 0)
	{
		ray_result->step_y = -1; // Si la direction est négative, on va verifier la case au dessus dans la carte
		ray_result->ray_dist_y = (game->player->player_pos_y - ray_result->map_pos_y) * ray_result->delta_dist_y; // Calcule la distance à la prochaine ligne de la carte sur l'axe y
	}
	else
	{
		ray_result->step_y = 1; // Si la direction est positive, on va verifier la case au dessous dans la carte
		ray_result->ray_dist_y = (ray_result->map_pos_y + 1.0 - game->player->player_pos_y) * ray_result->delta_dist_y; // Calcule la distance à la prochaine ligne de la carte sur l'axe y
	}
}

t_ray_result	ray_hit_detection(float ray_angle, t_game *game)
{
	t_ray_result	ray_result;

	initialize_ray(&ray_result, game, ray_angle);
	calcul_delta(&ray_result);
	initialize_ray_step_and_distance(&ray_result, game);
	ray_result.hit = 0;
	ray_result = perform_dda(ray_result, game->data->map);
	//cette ligne permet de calculer la hauteur du mur		    floor permet d'enleve le fisheye(distorsion visuel, les objets proches paraissent déformé)
	ray_result.wall_height = (int)((float)game->data->height / (floor(ray_result.ray_dist_perpendicular_to_wall * cos(clamp(game->player->angle - ray_angle, 0, 2 * M_PI)) * 1000) / 1000)); 
	ray_result.ray_angle = ray_angle;
	return (ray_result);
}
