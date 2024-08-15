/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:41:32 by tebandam          #+#    #+#             */
/*   Updated: 2024/08/15 09:11:55 by tebandam         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h" 

/*
* Struct
*/

typedef struct s_texture 
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
} t_texture;


typedef struct s_counter_parameter 
{
	int				counter_no;
	int				counter_so;
	int				counter_we;
	int				counter_ea;
	int				counter_f;
	int				counter_c;
}	t_counter_parameter;


typedef struct s_map
{
	int				fd;
	char			**map;
	int				weight;
	int				height;
	int				floor_color[4];
	int				ceiling_color[4];
}	t_map;



void	ft_print_value_map(t_map *map);
int		ft_parse_map_elements_wall(t_map *map);


/*
* Parsing arguments
*/

int		manage_cub_extension(char **argv);
int		parsing_arguments(int argc, char **argv);
int		ft_parse_map_elements(t_map *map);


/*
* Parsing colors
*/

int	ft_parse_map_elements_colors(t_map *map);


/*
* Textures
*/

int		load_north_south_textures(t_map *map, t_texture *texture, int i);
int		load_west_east_textures(t_map *map, t_texture *texture, int i);
int		ft_parse_map_path_texture(t_map *map, t_texture *texture);


/*
* Check and open file
*/

int check_and_open_file(t_map *map, char **argv);


/*
* Read map 
*/

char	**get_map(int fd);

/*
* Utils
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

/*
* ft_split
*/

char	**ft_split(char const *s, char c);


/*
* Error
*/

int		message_error_for_parsing_args(char *message, int ret_value);
int		message_error_for_missing_elements(t_counter_parameter counter_parameter);
int		message_error_for_texture_load(char *error_message);
/*
* Free
*/

void	ft_free(char **tab);

/*
* Allocation 
*/
// void	*ft_calloc(size_t nmemb, size_t size);

#endif