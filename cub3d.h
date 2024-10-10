/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/10 18:05:27 by ppuivif          ###   ########.fr       */
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
# include <math.h>
# include "get_next_line/get_next_line.h" 

# include <stdio.h> //to delete

#define WINDOWS_WIDTH 1040
#define WINDOWS_HEIGHT 720
#define TEX_WIDTH 64 // largeur de texture
#define TEX_HEIGHT 64 // hauteur de texture
#define LINE_HEIGHT 64 // test 

typedef unsigned int Uint32;

/*
* Struct
*/

typedef struct s_ray_result
{
	float	ray_angle; // non initialiser 
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
	float	wall_pos_hit; // l'endroit ou le rayon touche le mur
	int		draw_end; // ATTENTION VALEUR NON INITIALISER
	int		draw_start; // ATTENTION VALEUR NON INITIALISER
}	t_ray_result;

typedef struct s_player
{
	float	player_pos_x;
	float	player_pos_y;
	float	fov;
	float	angle;
	// float	pitch; 
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
	mlx_texture_t	*texture; // pas encore initialiser attention conditionnal jump

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
	char			**complete_map;
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
	t_ray_result		ray_result;
}	t_game;


void	texture_choice(t_game *game);
void	pos_texture(t_game *game);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b);
void	draw_wall_texture(t_game *game, int x);
void	draw_elements(mlx_image_t *image,
	int x, t_game *game, float wall_height);
/*
* Parsing arguments
*/

int		manage_cub_extension(char **argv);
void	parsing_arguments(int argc, char **argv);

/*
* Parsing colors
*/

int		ft_parse_map_elements_colors(t_map_data *map);

/*
* Parse map
*/

int		parse_map(t_map_data *map);
//void	parsing_map_elements(char **map, t_game *game);
void	parsing_map_elements(t_game *game);
void	parse_map_textures(t_game *game);

/*
* Images
*/

void	load_image(t_game *game);

/*
* Draw
*/

//void	 draw_elements(mlx_image_t* image, int x, float wall_height, t_game *game);
// void	draw_elements(mlx_image_t *image,
// 	int x, t_game *game);
/*
* Textures
*/

//int		load_north_south_textures(t_map_data *map, t_texture *texture, int i);
//int		load_west_east_textures(t_map_data *map, t_texture *texture, int i);
//int		parse_map_path_texture(t_map_data *map, t_texture *texture);

/*
* Check and open file
*/

void		check_and_open_file(int *fd, char **argv);

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
char	*ft_strchr(const char *s, int c);


/*
* ft_split
*/

char	**ft_split(char const *s, char c);

/*
* Error
*/

void	display_allocation_failed_and_exit();
int		message_error_for_missing_elements(
			t_counter_parameter counter_parameter);
int		message_error_return_1(char *error_message);


/*
* Allocations
*/

void	memory_allocation_for_structs(t_game **game);
void	allocate_textures(Uint32 *texture[8]);

/*
* Initialization
*/

void	initialization_of_values(t_game *game, char **map);

/*
* Free
*/

void	*free_array(char **arr);
//static void	delete_texture(t_texture *texture);
void	free_structs(t_game *game);

/*
* Divers help
*/

void	ft_print_value_map(char **map);
int		ft_parse_map_elements_wall(t_map_data *map);

/*
* display_minimap.c
*/

void    display_minimap(t_game *game);


#endif