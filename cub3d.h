/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/19 15:06:27 by ppuivif          ###   ########.fr       */
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

# define WINDOWS_WIDTH 1040
# define WINDOWS_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/*
* Struct
*/

typedef struct s_ray_result
{
	float	ray_angle;
	float	distance;
	float	ray_dist_x;
	float	ray_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	ray_dist_perpendicular_to_wall;
	int		wall_height;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_pos_x;
	int		map_pos_y;
	float	wall_pos_hit;
	int		draw_end;
	int		draw_start;
}	t_ray_result;

typedef struct s_player
{
	float	player_pos_x;
	float	player_pos_y;
	float	fov;
	float	angle;
}	t_player;

typedef struct s_texture
{
	mlx_image_t		*image;
	mlx_texture_t	*walls_image;
	mlx_texture_t	*floor_image;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*texture;
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
	int				fd;
	char			**file_content;
	char			**map;
	int				weight;
	int				height;
	int				nb_lines;
	int				nb_columns;
	int				*lines_lenght;
	int				begin_map_index;
	int				floor_color[4];
	int				ceiling_color[4];
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

/*
* parsing_args.c
*/

void			parsing_arguments(int argc, char **argv);

/*
* check_and_open_file.c
*/

void			check_and_open_file(int *fd, char **argv);

/*
* get_file_content.c 
*/

char			**get_file_content(int fd);

/*
* allocation.c
*/

void			memory_allocation_for_structs(t_game **game, \
				char **file_content);

/*
* initialization_of_values.c
*/

void			initialization_of_values(t_game *game, char **map);

/*
* parsing_map_textures.c
*/

void			parsing_file_textures(t_game *game);

/*
* parsing_map_path_textures.c
*/

void			parsing_file_path_textures(t_game *game);

/*
* parsing_map_colors.c
*/

void			parsing_file_colors(t_game *game);
int32_t			ft_pixel(int32_t r, int32_t g, int32_t b);

/*
* parsing_map.c
*/

void			parsing_map(t_game *game);

/*
* parsing_map_utils_1.c
*/

void			check_if_empty_line(char *line, t_game *game);
void			check_char_validity(char *line, t_game *game);
void			check_if_0_closed_by_1(t_game *game, char **filled_map);

/*
* parsing_map_utils_2.c
*/

void			get_player_initial_position_and_orientation(char *line, int i, \
				int *flag, t_game *game);
void			check_one_player(int flag, t_game *game);

/*
* render_graphics.c
*/

void			render_graphics(t_game *game);

/*
* movement.c
*/

void			ft_key_mouv(mlx_key_data_t keydata, void *param);

/*
* raycast.c
*/

void			raycast(void *param);

/*
* ray_hit_detection.c
*/

t_ray_result	ray_hit_detection(float ray_angle, t_game *game);

/*
* texture_displaying.c
*/

void			texture_choice(t_game *game);
void			pos_texture(t_game *game);
void			draw_wall_texture(t_game *game, int x);

/*
* draw_elements.c
*/

void			draw_elements(mlx_image_t *image, \
				int x, t_game *game, float wall_height);

/*
* error.c
*/

void			display_allocation_failed_and_exit(int fd);
void			exit_when_file_is_empty(int fd);
void			exit_when_incorrect_color_value(char **arr, t_game *game);
void			exit_when_space_reachable_by_player(char **map, t_game *game);
void			exit_when_0_non_closed_by_1(char **filled_map, t_game *game);

/*
* free.c
*/

void			*free_array(char **arr);
void			free_structs(t_game *game);

/*
* utils
*/

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strdup(const char *s);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
float			clamp(float num, float min, float max);
char			*ft_strchr(const char *s, int c);
int				ft_strcspn(char *remaining_line, char *str);
char			**ft_split(char const *s, char c);
char			*skip_first_spaces(char *str);
char			*ft_substr(char	const *s, unsigned int start, int len);
char			**arr_copy(char **arr);

#endif