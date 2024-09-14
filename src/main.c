/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:03:02 by tebandam          #+#    #+#             */
/*   Updated: 2024/09/14 12:31:34 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// mlx_loop_hook(p->game->mlx, ft_ray_casting, p);
// typedef struct s_ray_casting
// {
// 	float	angle;
// 	float	ray_dirx;
// 	float	ray_diry;
// 	int		mapx;
// 	int		mapy;
// 	float	side_distx;
// 	float	side_disty;
// 	float	delta_distx;
// 	float	delta_disty;
// 	int		stepx;
// 	int		stepy;
// 	int		side;
// 	int		hit;
// 	float	perp_wall_dist;
// 	float	last_pwd;
// 	float	distance_factor;
// 	float	wall_height;
// 	int		draw_start;
// 	int		draw_end;
// 	float	wall_hit_position;
// }	t_ray_casting;

// typedef struct s_game
// {
// 	mlx_t			*mlx;
// 	mlx_image_t		*image;
// 	int				width;
// 	int				height;
// 	int				mid_sx;
// 	int				mid_sy;
// 	bool			pause;
// 	mlx_texture_t	*text;
// 	uint32_t		*color_ray_text;
// 	mlx_texture_t	*dark_t;
// 	mlx_texture_t	*flash_t;
// 	mlx_image_t		*dark;
// 	mlx_image_t		*flash;
// 	mlx_image_t		*fps;
// 	mlx_image_t		*fps_min;
// 	mlx_image_t		*fps_max;
// 	char			*fps_mini;
// 	char			*fps_maxi;
// 	uint32_t		*color_north;
// 	uint32_t		*color_south;
// 	uint32_t		*color_west;
// 	uint32_t		*color_east;
// 	bool			cinematic;
// }	t_game;

// typedef struct s_player
// {
// 	float			posx;
// 	float			posy;
// 	float			move_speed;
// 	float			fov;
// 	float			or;
// 	bool			player_move_f;
// 	bool			player_move_b;
// 	bool			player_move_r;
// 	bool			player_move_l;
// 	bool			light_on;
// 	bool			player_look_left;
// 	bool			player_look_right;
// 	bool			player_run;
// 	float			last_mouse_x;
// 	float			last_mouse_y;

// 	float			buf_or;
// 	float			buf_fov;
// 	float			buf_py;
// 	float			buf_px;

// 	char			*freddy_walk;
	
// 	t_ray_casting	*rc;
// 	t_game			*game;
// 	t_data			*data;
// }	t_player;


// Afficher une image
// Faire bouger l'image 

//ft_print_value_map(&map);
int	main(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	if (parsing_arguments(argc, argv) == 1)
		return (EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	game->data = ft_calloc(1, sizeof(t_map_data));
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (check_and_open_file(game, argv) == 1)
		return (EXIT_FAILURE);
	game->data->map = get_map(game->data->fd);
	if (!game->data->map)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements(game->data) == 1)
		return (EXIT_FAILURE);
	if (ft_parse_map_path_texture(game->data, game->texture) != 0)
		return (EXIT_FAILURE);
	if (ft_parse_map_elements_colors(game->data) != 0)
		return (EXIT_FAILURE);
	parse_map(game->data);
	close(game->data->fd);
	game->mlx = mlx_init(1040, 720, "cub3d", false); // mlx_init permet de cree la fenêtre.
	mlx_loop(game->mlx); // mlx_loop permet d'afficher la fenêtre.
	mlx_close_window(game->mlx); // mlx_close_window permet de fermer la fenêtre.
	mlx_terminate(game->mlx); // mlx_terminate permet de fermer proprement la fenêtre
	ft_free(game->data->map);
	free(game->data);
	free(game->texture);
	free(game);
	ft_delete_texture(game->texture);
	ft_putstr_fd("\033[32mEnd of program 😊\033[0m\n", 1);
	return (EXIT_SUCCESS);
}












	
