/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/05 17:35:37 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
* Includes
*/

# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>
# include "get_next_line/get_next_line.h" 
# include "math.h"

# include <stdio.h> //to delete

#define WINDOWS_WIDTH 1040
#define WINDOWS_HEIGHT 720



typedef unsigned int Uint32;


/*
* Struct
*/

typedef struct s_ray_result
{
	float	distance;
	float	ray_dist_x; // distance du rayon en x
	float	ray_dist_y; // distance du rayon en y
	float	delta_dist_x; // distance que le rayon doit parcourir pour atteindre la prochaine ligne verticale
	float	delta_dist_y; // distance que le rayon doit parcourir pour atteindre la prochaine ligne horizontale
	float	ray_dist_perpendicular_to_wall; // distance du rayon perpendiculaire au mur
	int		wall_height;
	int		step_x; // test direction dans laquelle le rayon doit se déplacer en x
	int		step_y; // test direction dans laquelle le rayon doit se déplacer en y
	int		hit; // test a-t-il touché un mur?
	int		side; // test a-t-il touché un mur NS ou EW?
	int		map_pos_x; // test
	int		map_pos_y; // test
}	t_ray_result;

typedef struct s_player
{
	float	player_pos_x;
	float	player_pos_y;
	float	fov;
	float	angle;
	float	pitch;
}	t_player;

typedef struct s_texture
{
	mlx_image_t		*image;
	mlx_image_t		*player_position_image; //pour minimap
	
	mlx_image_t		*minimap; //pour minimap
	
	mlx_texture_t	*walls_image;
	mlx_texture_t	*floor_image;
	mlx_texture_t	*player_image; //pour minimap
	
	mlx_texture_t	*north_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;

	mlx_texture_t	*player_image_N; //pour minimap
	mlx_texture_t	*player_image_E; //pour minimap
	mlx_texture_t	*player_image_S; //pour minimap
	mlx_texture_t	*player_image_W; //pour minimap
	
}	t_texture;

typedef struct s_counter_parameter
{
	int				counter_no;
	int				counter_so;
	int				counter_we;
	int				counter_ea;
	int				counter_f;
	int				counter_c;
}	t_counter_parameter;

typedef struct s_map_data
{
	int				save;
	int				fd;
	char			**map;
	int				weight;
	int				height;
	int				nb_lines;
	int				nb_columns;
	int				floor_color[4];
	int				ceiling_color[4];
	float			direction;
}	t_map_data;

typedef struct s_game
{
	t_player			*player;
	mlx_t				*mlx;
	t_map_data			*data;
	t_counter_parameter	*counter_parameter;
	t_texture			*texture;
	t_ray_result		*ray_result;
}	t_game;

/*
* Parsing arguments
*/

int		manage_cub_extension(char **argv);
int		parsing_arguments(int argc, char **argv);
int		ft_parse_map_textures(t_map_data *map);

/*
* Parsing colors
*/

int		ft_parse_map_elements_colors(t_map_data *map);

/*
* Parse map
*/

int		parse_map(t_map_data *map);
void	parsing_map_elements(t_game *game);

/*
* Images
*/

void	load_image(t_game *game);

/*
* Draw
*/

void	 draw_elements(mlx_image_t* image, int x, float wall_height, t_game *game);

/*
* Textures
*/

int		load_north_south_textures(t_map_data *map, t_texture *texture, int i);
int		load_west_east_textures(t_map_data *map, t_texture *texture, int i);
int		ft_parse_map_path_texture(t_map_data *map, t_texture *texture);

/*
* Check and open file
*/

int		check_and_open_file(t_game *game, char **argv);

/*
* Read map 
*/

char	**get_map(int fd);

/*
* Parsing map Utils
*/

int				is_line_valid(char *str);
int				is_direction_valid(char *str, t_map_data *map_data);
int				is_top_and_bottom_wall_closed(char *str);
int				check_around_0(char	**line);

/*
* Render graphics
*/

void			render_graphics(t_game *game);

/*
* Raycasting
*/

void			raycast(void *param);
t_ray_result	ray_hit_detection(float ray_angle, t_game *game);

/*
* Move
*/

void	ft_key_mouv(mlx_key_data_t keydata, void *param);

/*
* Utils
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		is_full_whitespaces(char *str);
float	clamp(float num, float min, float max);

/*
* ft_split
*/

char	**ft_split(char const *s, char c);

/*
* Error
*/

int		message_error_for_parsing_args(char *message, int ret_value);
int		message_error_for_missing_elements(
			t_counter_parameter counter_parameter);
int		message_error_return_1(char *error_message);
int		free_tab_return_1(char **tab);


/*
* Allocations
*/

void	memory_allocation_for_struct(t_game **game);
void	allocate_textures(Uint32 *texture[8]);

/*
* Initialization
*/

void	initialization_of_values(t_game *game);

/*
* Free
*/

void	ft_free(char **tab);
void	ft_delete_texture(t_texture *texture);
void	close_and_free(t_game *game);

/*
* Divers help
*/

void	ft_print_value_map(t_map_data *map);
int		ft_parse_map_elements_wall(t_map_data *map);

/*
* display_minimap.c
*/

void    display_minimap(t_game *game);


#endif